/*
  Copyright (C) 2007 Gustavo I�iguez Goya

  gnome-inm-forecast is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "callbacks.h"


void on_radar_img_size_allocate 	( GtkWidget *widget, GtkAllocation *allocate, gpointer data )
{
/*
	GdkPixbuf *pix=0;
	int w=0, h=0;
	GtkImage *img = (GtkImage *) data;
	pix = gtk_image_get_pixbuf (GTK_IMAGE(img));
	//w = gdk_pixbuf_get_width (pix);
	//h = gdk_pixbuf_get_height (pix);
	gtk_window_get_size (GTK_WINDOW(widget), &w, &h);

	gtk_image_set_from_pixbuf (GTK_IMAGE(img), 
		gdk_pixbuf_scale_simple ( pix, w, h, GDK_INTERP_BILINEAR)
	);
*/
}

void on_window_terminate 	( GtkWidget *widget, gpointer data )
{
	GtkWidget *img = (GtkWidget *) data;
	if (img){
		GdkPixbuf *pix = gtk_image_get_pixbuf (GTK_IMAGE(img));
		if (pix){
			g_object_unref (G_OBJECT(pix));
			pix = 0;
		}
	}
	
	quit (widget);
}

void on_daily_temp_rb1_toggled			 ( GtkWidget *widget, gpointer data )
{
	GtkImage *img = (GtkImage *) data;
	GdkPixbuf *pixbuf;
	if (img){
		pixbuf = load_image (INM_DAILY_TEMPERATURE_MIN);
		if (pixbuf){
			gtk_image_set_from_pixbuf (GTK_IMAGE(img), pixbuf);
			gtk_widget_show (img);
			g_object_unref (G_OBJECT (pixbuf));
			pixbuf = 0;
		}
	}
}

void on_daily_temp_rb2_toggled			 ( GtkWidget *widget, gpointer data )
{
	GtkImage *img = (GtkImage *) data;
	GdkPixbuf *pixbuf;
	if (img){
		pixbuf = load_image (INM_DAILY_TEMPERATURE_MAX);
		if (pixbuf){
			gtk_image_set_from_pixbuf (GTK_IMAGE(img), pixbuf);
			gtk_widget_show (img);
			g_object_unref (G_OBJECT (pixbuf));
			pixbuf = 0;
		}
	}
}

void on_rb_00_toggled			 ( GtkWidget *widget, gpointer data )
{
	GtkImage *img = (GtkImage *) data;
	GdkPixbuf *pixbuf;
	if (img){
		pixbuf = load_image (INM_RADAR0000_IMG);
		if (pixbuf){
			gtk_image_set_from_pixbuf (GTK_IMAGE(img), pixbuf);
			g_object_unref (G_OBJECT (pixbuf));
			pixbuf = 0;
		}
	}
}

void on_rb_06_toggled 			( GtkWidget *widget, gpointer data )
{
	GtkImage *img = (GtkImage *) data;
	GdkPixbuf *pixbuf;
	if (img){
		pixbuf = load_image (INM_RADAR0600_IMG);
		if (pixbuf){
			gtk_image_set_from_pixbuf (GTK_IMAGE(img), pixbuf);
			g_object_unref (G_OBJECT (pixbuf));
			pixbuf = 0;
		}
	}
}

void on_rb_12_toggled 			( GtkWidget *widget, gpointer data )
{
	GtkImage *img = (GtkImage *) data;
	GdkPixbuf *pixbuf;
	if (img){
		pixbuf = load_image (INM_RADAR1200_IMG);
		if (pixbuf){
			gtk_image_set_from_pixbuf (GTK_IMAGE(img), pixbuf);
			g_object_unref (G_OBJECT (pixbuf));
			pixbuf = 0;
		}
	}
}

void on_rb_18_toggled ( GtkWidget *widget, gpointer data )
{
	GtkImage *img = (GtkImage *) data;
	GdkPixbuf *pixbuf;
	if (img){
		pixbuf = load_image (INM_RADAR1800_IMG);
		if (pixbuf){
			gtk_image_set_from_pixbuf (GTK_IMAGE(img), pixbuf);
			g_object_unref (G_OBJECT (pixbuf));
			pixbuf = 0;
		}
	}
}

void on_applet_destroy 			( GtkWidget *widget, AppletData *applet_data )
{
	printf ("Applet destroy\n");
	if (applet_data){
		gtk_timeout_remove (applet_data->timer);
		g_free (applet_data->day_info);
		g_free (applet_data->prefs);
		g_free (applet_data);
	}

}

gboolean on_image_button_press 	( GtkWidget *event_box, GdkEventButton *event, AppletData *applet_data )
{
	if (event->button != 1)
		return FALSE;
		
	//printf ("event: %s\n", event_box->name);
	/*
	if (strcmp (event_box->name, "event11") == 0)
		check_latest_data (applet_data);
	else
	*/
	create_window ( applet_data, event_box->name );

	return TRUE;
}
