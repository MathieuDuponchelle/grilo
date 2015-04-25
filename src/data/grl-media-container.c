/*
 * Copyright (C) 2015 Collabora.
 *
 * Authors: Mathieu Duponchelle <mathieu.duponchelle@collabora.com>
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

/**
 * SECTION:grl-media-container
 * @short_description: A multimedia data for a container format
 * @see_also: #GrlConfig, #GrlMediaBox, #GrlMediaAudio, #GrlMediaImage,
 * #GrlMediaVideo
 *
 * This high level class represents a container multimedia item. It has methods to
 * set and access the contained #GrlMedia. Examples of multimedia containers
 * are ogg, avi, mp4 ...
 */

#include "grl-media-container.h"


G_DEFINE_TYPE (GrlMediaContainer, grl_media_container, GRL_TYPE_MEDIA);

static void
grl_media_container_finalize (GObject * object)
{
  GrlMediaContainer *container = GRL_MEDIA_CONTAINER (object);
  GList *contained_media = grl_media_container_get_media (container);
  GList *tmp;

  for (tmp = contained_media; tmp; tmp = tmp->next) {
    grl_data_set (GRL_DATA (tmp->data), GRL_METADATA_KEY_MEDIA_CONTAINER, NULL);
  }

  g_list_free_full (contained_media, g_object_unref);

  G_OBJECT_CLASS (grl_media_container_parent_class)->finalize (object);
}

static void
grl_media_container_class_init (GrlMediaContainerClass * klass)
{
  GObjectClass *gobject_class = (GObjectClass *) klass;

  gobject_class->finalize = grl_media_container_finalize;
}

static void
grl_media_container_init (GrlMediaContainer * self)
{
}

static void
_set_container_on_media (GrlMediaContainer * container, GrlMedia * media)
{
  GValue value = { 0 };

  g_value_init (&value, G_TYPE_POINTER);
  g_value_set_pointer (&value, container);

  grl_data_set (GRL_DATA (media), GRL_METADATA_KEY_MEDIA_CONTAINER, &value);
  g_value_unset (&value);
}

static GrlMediaContainer *
_get_container_from_media (GrlMedia * media)
{
  const GValue *value =
      grl_data_get (GRL_DATA (media), GRL_METADATA_KEY_MEDIA_CONTAINER);
  if (!value)
    return NULL;

  return g_value_get_pointer (value);
}

/**
 * grl_media_container_add_media:
 * @container: a #GrlMediaContainer
 * @media: (transfer none): a #GrlMedia.
 *
 * Add @media to @container, taking a reference on it.
 * A #GrlMedia can only be added to one #GrlMediaContainer.
 *
 * Returns: #TRUE if the media could successfully be added, #FALSE
 * otherwise.
 *
 * Since: 0.2
 */
gboolean
grl_media_container_add_media (GrlMediaContainer * container, GrlMedia * media)
{
  GrlRelatedKeys *keys;
  GValue value = { 0 };

  g_return_val_if_fail (GRL_IS_MEDIA_CONTAINER (container), FALSE);
  g_return_val_if_fail (GRL_IS_MEDIA (media), FALSE);

  if (_get_container_from_media (media))
    return FALSE;

  g_value_init (&value, GRL_TYPE_MEDIA);
  g_value_set_object (&value, media);
  keys = grl_related_keys_new ();

  grl_related_keys_set (keys, GRL_METADATA_KEY_CONTAINED_MEDIA, &value);
  grl_data_add_related_keys (GRL_DATA (container), keys);

  _set_container_on_media (container, media);

  g_value_unset (&value);
  return TRUE;
}

/**
 * grl_media_container_get_media:
 * @container: A #GrlMediaContainer
 * 
 * Returns the list of #GrlMedia contained by @container.
 *
 * Returns: (transfer full) (element-type GrlMedia): the list of
 * #GrlMedia contained by @container.
 *
 * Since: 0.2
 */
GList *
grl_media_container_get_media (GrlMediaContainer * container)
{
  GList *media = NULL;
  gint i;

  for (i =
      grl_data_length (GRL_DATA (container),
          GRL_METADATA_KEY_CONTAINED_MEDIA) - 1; i >= 0; i--) {
    GrlRelatedKeys *keys = grl_data_get_related_keys (GRL_DATA (container),
        GRL_METADATA_KEY_CONTAINED_MEDIA, i);
    const GValue *value =
        grl_related_keys_get (keys, GRL_METADATA_KEY_CONTAINED_MEDIA);

    media = g_list_prepend (media, g_object_ref (g_value_get_object (value)));
  }

  return media;
}

/**
 * grl_media_container_new:
 *
 * Creates a new data container object.
 *
 * Returns: a newly-allocated data container.
 *
 * Since: 0.2
 */
GrlMedia *
grl_media_container_new (void)
{
  return GRL_MEDIA (g_object_new (GRL_TYPE_MEDIA_CONTAINER, NULL));
}
