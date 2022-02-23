// File: helloworld.h

#ifndef GTKMM_HELLOWORLD_EXAMPLE_H
#define GTKMM_HELLOWORLD_EXAMPLE_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class GtkViewer : public Gtk::Window
{

public:
  GtkViewer();
  virtual ~GtkViewer();

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Button m_button;
};

#endif