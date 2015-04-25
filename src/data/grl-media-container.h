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

#if !defined (_GRILO_H_INSIDE_) && !defined (GRILO_COMPILATION)
#error "Only <grilo.h> can be included directly."
#endif

#ifndef _GRL_MEDIA_CONTAINER_H_
#define _GRL_MEDIA_CONTAINER_H_

#include <grl-media.h>
#include <grl-definitions.h>

G_BEGIN_DECLS

#define GRL_TYPE_MEDIA_CONTAINER                    \
  (grl_media_container_get_type())

#define GRL_MEDIA_CONTAINER(obj)                            \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj),                   \
                               GRL_TYPE_MEDIA_CONTAINER,    \
                               GrlMediaContainer))

#define GRL_MEDIA_CONTAINER_CLASS(klass)                    \
  (G_TYPE_CHECK_CLASS_CAST ((klass),                    \
                            GRL_TYPE_MEDIA_CONTAINER,       \
                            GrlMediaContainerClass))

#define GRL_IS_MEDIA_CONTAINER(obj)                         \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj),                   \
                               GRL_TYPE_MEDIA_CONTAINER))

#define GRL_IS_MEDIA_CONTAINER_CLASS(klass)                 \
  (G_TYPE_CHECK_CLASS_TYPE ((klass),                    \
                            GRL_TYPE_MEDIA_CONTAINER))

#define GRL_MEDIA_CONTAINER_GET_CLASS(obj)                  \
  (G_TYPE_INSTANCE_GET_CLASS ((obj),                    \
                              GRL_TYPE_MEDIA_CONTAINER,     \
                              GrlMediaContainerClass))

typedef struct _GrlMediaContainer      GrlMediaContainer;
typedef struct _GrlMediaContainerClass GrlMediaContainerClass;

struct _GrlMediaContainer
{
  GrlMedia parent;

  /*< private >*/
  gpointer _grl_reserved[GRL_PADDING_SMALL];
};

/**
 * GrlMediaContainerClass:
 * @parent_class: the parent class structure
 *
 * Grilo Media container Class
 */
struct _GrlMediaContainerClass
{
  GrlMediaClass parent_class;

  /*< private >*/
  gpointer _grl_reserved[GRL_PADDING];
};

GType grl_media_container_get_type (void) G_GNUC_CONST;

gboolean grl_media_container_add_media (GrlMediaContainer *container, GrlMedia *media);
GList *grl_media_container_get_media (GrlMediaContainer *container);

GrlMedia *grl_media_container_new (void);


G_END_DECLS

#endif /* _GRL_MEDIA_CONTAINER_H_ */
