/*
 * Copyright (C) 2015 Mathieu Duponchelle <mathieu.duponchelle@collabora.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#undef G_DISABLE_ASSERT

#include <glib.h>
#include <grilo.h>

#define CHECK_MESSAGE(domain, error_message) \
  (g_strcmp0 (log_domain, domain) == 0 && strstr (message, error_message))

#define G_OBJECT_REFCOUNT(obj)                (((GObject*)(obj))->ref_count)
#define G_OBJECT_REFCOUNT_VALUE(obj)          g_atomic_int_get ((gint *) &G_OBJECT_REFCOUNT(obj))

#define ASSERT_OBJECT_REFCOUNT(object, value)             \
G_STMT_START {                                                  \
  int refcount;                                                       \
  refcount = G_OBJECT_REFCOUNT_VALUE (object);                      \
  g_assert_cmpint (refcount, ==, value);                            \
} G_STMT_END

static void
media_container_refcounts (void)
{
  GrlMediaContainer *container =
      GRL_MEDIA_CONTAINER (grl_media_container_new ());
  GrlMedia *audio = grl_media_audio_new ();
  GList *contained_media;

  ASSERT_OBJECT_REFCOUNT (container, 1);
  ASSERT_OBJECT_REFCOUNT (audio, 1);

  grl_media_container_add_media (container, audio);
  /* The container takes a reference to the media */
  ASSERT_OBJECT_REFCOUNT (audio, 2);
  /* But the media shouldn't take a ref on its container */
  ASSERT_OBJECT_REFCOUNT (container, 1);

  contained_media = grl_media_container_get_media (container);
  /* We've got new references to the media */
  ASSERT_OBJECT_REFCOUNT (audio, 3);

  /* release these references */
  g_list_free_full (contained_media, g_object_unref);
  ASSERT_OBJECT_REFCOUNT (audio, 2);

  /* Free the container, this should release the references it took */
  ASSERT_OBJECT_REFCOUNT (container, 1);
  g_object_unref (container);
  ASSERT_OBJECT_REFCOUNT (audio, 1);

  g_object_unref (audio);
}

static void
media_container_already_added (void)
{
  GrlMediaContainer *container =
      GRL_MEDIA_CONTAINER (grl_media_container_new ());
  GrlMediaContainer *container2 =
      GRL_MEDIA_CONTAINER (grl_media_container_new ());
  GrlMedia *audio = grl_media_audio_new ();

  g_assert_true (grl_media_container_add_media (container, audio));
  /* Can't add a media to two containers */
  g_assert_false (grl_media_container_add_media (container2, audio));

  g_object_unref (container);

  /* Not sure how much of a use case that is but let's cover it anyway */
  g_assert_true (grl_media_container_add_media (container2, audio));

  g_object_unref (container2);
  g_object_unref (audio);
}

int
main (int argc, char **argv)
{
  g_test_init (&argc, &argv, NULL);

  g_test_bug_base ("http://bugs.gnome.org/%s");

  grl_init (&argc, &argv);

  g_test_add_func ("/media-container/refcounts", media_container_refcounts);
  g_test_add_func ("/media-container/already_added",
      media_container_already_added);

  return g_test_run ();
}
