/*
 * Copyright (C) 2010, 2011 Igalia S.L.
 *
 * Contact: Iago Toral Quiroga <itoral@igalia.com>
 *
 * Authors: Juan A. Suarez Romero <jasuarez@igalia.com>
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
 * SECTION:grl-media-video
 * @short_description: A multimedia data for video
 * @see_also: #GrlConfig, #GrlMediaBox, #GrlMediaAudio, #GrlMediaImage
 *
 * This high level class represents an video multimedia item. It has methods to
 * set and get properties like framerate, width, height, and so on.
 */

#include "grl-media-video.h"


static void grl_media_video_finalize (GObject *object);

G_DEFINE_TYPE (GrlMediaVideo, grl_media_video, GRL_TYPE_MEDIA);

static void
grl_media_video_class_init (GrlMediaVideoClass *klass)
{
  GObjectClass *gobject_class = (GObjectClass *)klass;

  gobject_class->finalize = grl_media_video_finalize;
}

static void
grl_media_video_init (GrlMediaVideo *self)
{
}

static void
grl_media_video_finalize (GObject *object)
{
  g_signal_handlers_destroy (object);
  G_OBJECT_CLASS (grl_media_video_parent_class)->finalize (object);
}

/**
 * grl_media_video_new:
 *
 * Creates a new data video object.
 *
 * Returns: a newly-allocated data video.
 *
 * Since: 0.1.4
 */
GrlMedia *
grl_media_video_new (void)
{
  return GRL_MEDIA (g_object_new (GRL_TYPE_MEDIA_VIDEO,
                                  NULL));
}

/**
 * grl_media_video_set_size:
 * @video: the media instance
 * @width: the video's width
 * @height: the video's height
 *
 * Set the width and the height of the video
 *
 * Since: 0.1.4
 */
void
grl_media_video_set_size (GrlMediaVideo *video,
                          gint width,
                          int height)
{
  g_return_if_fail (GRL_IS_MEDIA_VIDEO (video));

  grl_media_video_set_width (video, width);
  grl_media_video_set_height (video, height);
}

/**
 * grl_media_video_set_width:
 * @video: the media instance
 * @width: the video's width
 *
 * Set the width of the video
 *
 * Since: 0.1.4
 */
void
grl_media_video_set_width (GrlMediaVideo *video, gint width)
{
  grl_data_set_int (GRL_DATA (video),
                    GRL_METADATA_KEY_WIDTH,
                    width);
}

/**
 * grl_media_video_set_height:
 * @video: the media instance
 * @height: the video's height
 *
 * Set the height of the video
 *
 * Since: 0.1.4
 */
void
grl_media_video_set_height (GrlMediaVideo *video, gint height)
{
  grl_data_set_int (GRL_DATA (video),
                    GRL_METADATA_KEY_HEIGHT,
                    height);
}

/**
 * grl_media_video_set_framerate:
 * @video: the media instance
 * @framerate: the video's framerate
 *
 * Set the framerate of the video
 *
 * Since: 0.1.4
 */
void
grl_media_video_set_framerate (GrlMediaVideo *video, gfloat framerate)
{
  grl_data_set_float (GRL_DATA (video),
                      GRL_METADATA_KEY_FRAMERATE,
                      framerate);
}

/**
 * grl_media_video_set_season:
 * @video: the media instance
 * @season: the video's season
 *
 * Sets the season number of the video
 *
 * Since: 0.1.11
 */
void
grl_media_video_set_season (GrlMediaVideo *video, gint season)
{
  grl_data_set_int (GRL_DATA (video), GRL_METADATA_KEY_SEASON, season);
}

/**
 * grl_media_video_set_episode:
 * @video: the media instance
 * @episode: the video's episode
 *
 * Sets the episode number of the video
 *
 * Since: 0.1.11
 */
void
grl_media_video_set_episode (GrlMediaVideo *video, gint episode)
{
  grl_data_set_int (GRL_DATA (video), GRL_METADATA_KEY_EPISODE, episode);
}

/**
 * grl_media_video_set_episode_title:
 * @video: the media instance
 * @episode_title: the title of the episode
 *
 * Sets the title of an episode
 *
 * Since: 0.2.12
 */
void
grl_media_video_set_episode_title (GrlMediaVideo *video,
                                   const gchar *episode_title)
{
  g_return_if_fail (GRL_IS_MEDIA_VIDEO (video));

  grl_data_set_string (GRL_DATA (video),
                       GRL_METADATA_KEY_EPISODE_TITLE,
                       episode_title);
}

/**
 * grl_media_video_set_show:
 * @video: the media instance
 * @show: the video's show name
 *
 * Sets the show title of the video
 *
 * Since: 0.1.11
 */
void
grl_media_video_set_show (GrlMediaVideo *video, const gchar *show)
{
  grl_data_set_string (GRL_DATA (video), GRL_METADATA_KEY_SHOW, show);
}

/**
 * grl_media_video_get_width:
 * @video: the media instance
 *
 * Returns: the width of the video
 *
 * Since: 0.1.4
 */
gint
grl_media_video_get_width (GrlMediaVideo *video)
{
  return grl_data_get_int (GRL_DATA (video), GRL_METADATA_KEY_WIDTH);
}

/**
 * grl_media_video_get_height:
 * @video: the media instance
 *
 * Returns: the height of the video
 *
 * Since: 0.1.4
 */
gint
grl_media_video_get_height (GrlMediaVideo *video)
{
  return grl_data_get_int (GRL_DATA (video), GRL_METADATA_KEY_HEIGHT);
}

/**
 * grl_media_video_get_framerate:
 * @video: the media instance
 *
 * Returns: the framerate of the video
 *
 * Since: 0.1.4
 */
gfloat
grl_media_video_get_framerate (GrlMediaVideo *video)
{
  return grl_data_get_float (GRL_DATA (video), GRL_METADATA_KEY_FRAMERATE);
}

/**
 * grl_media_video_get_season:
 * @video: the media instance
 *
 * Returns: the season number of the video
 *
 * Since: 0.1.11
 */
gint
grl_media_video_get_season (GrlMediaVideo *video)
{
  return grl_data_get_int (GRL_DATA (video), GRL_METADATA_KEY_SEASON);
}

/**
 * grl_media_video_get_episode:
 * @video: the media instance
 *
 * Returns: the episode number of the video
 *
 * Since: 0.1.11
 */
gint
grl_media_video_get_episode (GrlMediaVideo *video)
{
  return grl_data_get_int (GRL_DATA (video), GRL_METADATA_KEY_EPISODE);
}

/**
 * grl_media_video_get_episode_title:
 * @video: the media instance
 *
 * Returns: the title of the episode
 *
 * Since: 0.2.12
 */
const gchar *
grl_media_video_get_episode_title (GrlMediaVideo *video)
{
  g_return_val_if_fail (GRL_IS_MEDIA_VIDEO (video), NULL);

  return grl_data_get_string (GRL_DATA (video), GRL_METADATA_KEY_EPISODE_TITLE);
}

/**
 * grl_media_video_get_show:
 * @video: the media instance
 *
 * Returns: the show title of the video
 *
 * Since: 0.1.11
 */
const gchar *
grl_media_video_get_show (GrlMediaVideo *video)
{
  return grl_data_get_string (GRL_DATA (video), GRL_METADATA_KEY_SHOW);
}

/**
 * grl_media_video_set_url_data:
 * @video: the media instance
 * @url: the video's url
 * @mime: video mime-type
 * @framerate: video framerate, or -1 to ignore
 * @width: video width, or -1 to ignore
 * @height: video height, or -1 to ignore
 *
 * Sets all the keys related with the URL of a video resource in one go.
 *
 * Since: 0.1.10
 **/
void
grl_media_video_set_url_data (GrlMediaVideo *video,
                              const gchar *url,
                              const gchar *mime,
                              gfloat framerate,
                              gint width,
                              gint height)
{
  GrlRelatedKeys *relkeys;

  g_return_if_fail (GRL_IS_MEDIA_VIDEO (video));

  relkeys = grl_related_keys_new ();
  grl_related_keys_set_string (relkeys, GRL_METADATA_KEY_URL, url);
  grl_related_keys_set_string (relkeys, GRL_METADATA_KEY_MIME, mime);
  if (framerate >= 0) {
    grl_related_keys_set_float (relkeys, GRL_METADATA_KEY_FRAMERATE, framerate);
  }
  if (width >= 0) {
    grl_related_keys_set_int (relkeys, GRL_METADATA_KEY_WIDTH, width);
  }
  if (height >= 0) {
    grl_related_keys_set_int (relkeys, GRL_METADATA_KEY_HEIGHT, height);
  }
  grl_data_set_related_keys (GRL_DATA (video), relkeys, 0);
}

/**
 * grl_media_video_add_url_data:
 * @video: the media instance
 * @url: a video's url
 * @mime: video mime-type
 * @framerate: video framerate, or -1 to ignore
 * @width: video width, or -1 to ignore
 * @height: video height, or -1 to ignore
 *
 * Sets all the keys related with the URL of a media resource and adds it to
 * @video (useful for resources with more than one URL).
 *
 * Since: 0.1.10
 **/
void
grl_media_video_add_url_data (GrlMediaVideo *video,
                              const gchar *url,
                              const gchar *mime,
                              gfloat framerate,
                              gint width,
                              gint height)
{
  GrlRelatedKeys *relkeys;

  g_return_if_fail (GRL_IS_MEDIA_VIDEO (video));

  relkeys = grl_related_keys_new ();
  grl_related_keys_set_string (relkeys, GRL_METADATA_KEY_URL, url);
  grl_related_keys_set_string (relkeys, GRL_METADATA_KEY_MIME, mime);
  if (framerate >= 0) {
    grl_related_keys_set_float (relkeys, GRL_METADATA_KEY_FRAMERATE, framerate);
  }
  if (width >= 0) {
    grl_related_keys_set_int (relkeys, GRL_METADATA_KEY_WIDTH, width);
  }
  if (height >= 0) {
    grl_related_keys_set_int (relkeys, GRL_METADATA_KEY_HEIGHT, height);
  }
  grl_data_add_related_keys (GRL_DATA (video), relkeys);
}

/**
 * grl_media_video_get_url_data:
 * @video: the media instance
 * @mime: (out) (transfer none): the url mime-type, or %NULL to ignore
 * @framerate: the url framerate, or %NULL to ignore
 * @width: the url width, or %NULL to ignore
 * @height: the url height, or %NULL to ignore
 *
 * Returns: all the keys related with the URL of a video resource in one go.
 *
 * Since: 0.1.10
 **/
const gchar *
grl_media_video_get_url_data (GrlMediaVideo *video,
                              gchar **mime,
                              gfloat *framerate,
                              gint *width,
                              gint *height)
{
  return grl_media_video_get_url_data_nth (video,
                                           0,
                                           mime,
                                           framerate,
                                           width,
                                           height);
}

/**
 * grl_media_video_get_url_data_nth:
 * @video: the media instance
 * @index: element to retrieve
 * @mime: (out) (transfer none): the url mime-type, or %NULL to ignore
 * @framerate: the url framerate, or %NULL to ignore
 * @width: the url width, or %NULL to ignore
 * @height: the url height, or %NULL to ignore
 *
 * Returns: all the keys related with the URL number @index of a video resource
 * in one go.
 *
 * Since: 0.1.10
 **/
const gchar *
grl_media_video_get_url_data_nth (GrlMediaVideo *video,
                                  guint index,
                                  gchar **mime,
                                  gfloat *framerate,
                                  gint *width,
                                  gint *height)
{
  GrlRelatedKeys *relkeys;

  g_return_val_if_fail (GRL_IS_MEDIA_VIDEO (video), NULL);

  relkeys =
    grl_data_get_related_keys (GRL_DATA (video), GRL_METADATA_KEY_URL, index);

  if (!relkeys) {
    return NULL;
  }

  if (mime) {
    *mime = (gchar *) grl_related_keys_get_string (relkeys,
                                                   GRL_METADATA_KEY_MIME);
  }

  if (framerate) {
    *framerate = grl_related_keys_get_float (relkeys,
                                             GRL_METADATA_KEY_FRAMERATE);
  }

  if (width) {
    *width = grl_related_keys_get_int (relkeys, GRL_METADATA_KEY_WIDTH);
  }

  if (height) {
    *height = grl_related_keys_get_int (relkeys, GRL_METADATA_KEY_HEIGHT);
  }

  return grl_related_keys_get_string (relkeys, GRL_METADATA_KEY_URL);
}

/**
 * grl_media_video_set_performer:
 * @video: a #GrlMediaVideo
 * @performer: an actor performing in the movie
 *
 * Sets the actor performing in the movie.
 *
 * Since: 0.2.3
 */
void
grl_media_video_set_performer (GrlMediaVideo *video,
                               const gchar *performer)
{
  grl_data_set_string (GRL_DATA (video),
                       GRL_METADATA_KEY_PERFORMER,
                       performer);
}

/**
 * grl_media_video_add_performer:
 * @video: a #GrlMediaVideo
 * @performer: an actor performing in the movie
 *
 * Adds the actor performing in the movie.
 *
 * Since: 0.2.3
 */
void
grl_media_video_add_performer (GrlMediaVideo *video,
                               const gchar *performer)
{
  grl_data_add_string (GRL_DATA (video),
                       GRL_METADATA_KEY_PERFORMER,
                       performer);
}

/**
 * grl_media_video_get_performer:
 * @video: a #GrlMediaVideo
 *
 * Returns: (transfer none): the actor performing in the movie (owned by @video).
 *
 * Since: 0.2.3
 */
const gchar *
grl_media_video_get_performer (GrlMediaVideo *video)
{
  return grl_data_get_string (GRL_DATA (video),
                              GRL_METADATA_KEY_PERFORMER);
}

/**
 * grl_media_video_get_performer_nth:
 * @video: a #GrlMediaVideo
 * @index: element to retrieve
 *
 * Returns: (transfer none): the actor performing in the movie (owned by @video).
 *
 * Since: 0.2.3
 */
const gchar *
grl_media_video_get_performer_nth (GrlMediaVideo *video,
                                   guint index)
{
  GrlRelatedKeys *relkeys;

  g_return_val_if_fail (GRL_IS_MEDIA_VIDEO (video), NULL);

  relkeys =
    grl_data_get_related_keys (GRL_DATA (video),
                               GRL_METADATA_KEY_PERFORMER,
                               index);

  if (!relkeys) {
    return NULL;
  }

  return grl_related_keys_get_string (relkeys,
                                      GRL_METADATA_KEY_PERFORMER);
}

/**
 * grl_media_video_set_producer:
 * @video: a #GrlMediaVideo
 * @producer: producer of the movie
 *
 * Sets the producer of the movie.
 *
 * Since: 0.2.3
 */
void
grl_media_video_set_producer (GrlMediaVideo *video,
                              const gchar *producer)
{
  grl_data_set_string (GRL_DATA (video),
                       GRL_METADATA_KEY_PRODUCER,
                       producer);
}

/**
 * grl_media_video_add_producer:
 * @video: a #GrlMediaVideo
 * @producer: producer of the movie
 *
 * Adds the producer of the movie.
 *
 * Since: 0.2.3
 */
void
grl_media_video_add_producer (GrlMediaVideo *video,
                              const gchar *producer)
{
  grl_data_add_string (GRL_DATA (video),
                       GRL_METADATA_KEY_PRODUCER,
                       producer);
}

/**
 * grl_media_video_get_producer:
 * @video: a #GrlMediaVideo
 *
 * Returns: (transfer none): the producer of the movie (owned by @video).
 *
 * Since: 0.2.3
 */
const gchar *
grl_media_video_get_producer (GrlMediaVideo *video)
{
  return grl_data_get_string (GRL_DATA (video),
                              GRL_METADATA_KEY_PRODUCER);
}

/**
 * grl_media_video_get_producer_nth:
 * @video: a #GrlMediaVideo
 * @index: element to retrieve
 *
 * Returns: (transfer none): the producer of the movie (owned by @video).
 *
 * Since: 0.2.3
 */
const gchar *
grl_media_video_get_producer_nth (GrlMediaVideo *video,
                                  guint index)
{
  GrlRelatedKeys *relkeys;

  g_return_val_if_fail (GRL_IS_MEDIA_VIDEO (video), NULL);

  relkeys =
    grl_data_get_related_keys (GRL_DATA (video),
                               GRL_METADATA_KEY_PRODUCER,
                               index);

  if (!relkeys) {
    return NULL;
  }

  return grl_related_keys_get_string (relkeys,
                                      GRL_METADATA_KEY_PRODUCER);
}

/**
 * grl_media_video_set_director:
 * @video: a #GrlMediaVideo
 * @director: director of the movie
 *
 * Sets the director of the movie.
 *
 * Since: 0.2.3
 */
void
grl_media_video_set_director (GrlMediaVideo *video,
                              const gchar *director)
{
  grl_data_set_string (GRL_DATA (video),
                       GRL_METADATA_KEY_DIRECTOR,
                       director);
}

/**
 * grl_media_video_add_director:
 * @video: a #GrlMediaVideo
 * @director: director of the movie
 *
 * Adds the director of the movie.
 *
 * Since: 0.2.3
 */
void
grl_media_video_add_director (GrlMediaVideo *video,
                              const gchar *director)
{
  grl_data_add_string (GRL_DATA (video),
                       GRL_METADATA_KEY_DIRECTOR,
                       director);
}

/**
 * grl_media_video_get_director:
 * @video: a #GrlMediaVideo
 *
 * Returns: (transfer none): the director of the movie (owned by @video).
 *
 * Since: 0.2.3
 */
const gchar *
grl_media_video_get_director (GrlMediaVideo *video)
{
  return grl_data_get_string (GRL_DATA (video),
                              GRL_METADATA_KEY_DIRECTOR);
}

/**
 * grl_media_video_get_director_nth:
 * @video: a #GrlMediaVideo
 * @index: element to retrieve
 *
 * Returns: (transfer none): the director of the movie (owned by @video).
 *
 * Since: 0.2.3
 */
const gchar *
grl_media_video_get_director_nth (GrlMediaVideo *video,
                                  guint index)
{
  GrlRelatedKeys *relkeys;

  g_return_val_if_fail (GRL_IS_MEDIA_VIDEO (video), NULL);

  relkeys =
    grl_data_get_related_keys (GRL_DATA (video),
                               GRL_METADATA_KEY_DIRECTOR,
                               index);

  if (!relkeys) {
    return NULL;
  }

  return grl_related_keys_get_string (relkeys,
                                      GRL_METADATA_KEY_DIRECTOR);
}

/**
 * grl_media_video_set_original_title:
 * @video: a #GrlMediaVideo
 * @original_title: original, untranslated title of the movie
 *
 * Sets the original, untranslated title of the movie.
 *
 * Since: 0.2.3
 */
void
grl_media_video_set_original_title (GrlMediaVideo *video,
                                    const gchar *original_title)
{
  grl_data_set_string (GRL_DATA (video),
                       GRL_METADATA_KEY_ORIGINAL_TITLE,
                       original_title);
}

/**
 * grl_media_video_get_original_title:
 * @video: a #GrlMediaVideo
 *
 * Returns: (transfer none): the original, untranslated title of the movie (owned by @video).
 *
 * Since: 0.2.3
 */
const gchar *
grl_media_video_get_original_title (GrlMediaVideo *video)
{
  return grl_data_get_string (GRL_DATA (video),
                              GRL_METADATA_KEY_ORIGINAL_TITLE);
}
