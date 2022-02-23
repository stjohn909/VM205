// File: main.cc

#include "vm205/Gtkviewer.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "helloworld");

  GtkViewer gtkviewer;

  //Shows the window and returns when it is closed.
  return app->run(helloworld);
}