EXTRA_DIST =
CLEANFILES =

if ENABLE_VAPIGEN
-include $(VAPIGEN_MAKEFILE)

VAPIGEN_VAPIS = grilo-@GRL_MAJORMINOR@.vapi grilo-net-@GRL_MAJORMINOR@.vapi

grilo-@GRL_MAJORMINOR@.vapi: $(top_builddir)/src/Grl-@GRL_MAJORMINOR@.gir grilo-@GRL_MAJORMINOR@-custom.vala grilo-@GRL_MAJORMINOR@.deps Grl-@GRL_MAJORMINOR@.metadata

grilo_@GRL_MAJORMINOR_NORM@_vapi_DEPS = gio-2.0
grilo_@GRL_MAJORMINOR_NORM@_vapi_METADATADIRS = $(srcdir)
grilo_@GRL_MAJORMINOR_NORM@_vapi_FILES = $(srcdir)/grilo-@GRL_MAJORMINOR@-custom.vala $(top_builddir)/src/Grl-@GRL_MAJORMINOR@.gir

EXTRA_DIST += Grl-@GRL_MAJORMINOR@.metadata grilo-@GRL_MAJORMINOR@.deps grilo-@GRL_MAJORMINOR@-custom.vala

grilo-net-@GRL_MAJORMINOR@.vapi:  $(top_builddir)/libs/net/GrlNet-@GRL_MAJORMINOR@.gir grilo-net-@GRL_MAJORMINOR@-custom.vala grilo-net-@GRL_MAJORMINOR@.deps GrlNet-@GRL_MAJORMINOR@.metadata

grilo_net_@GRL_MAJORMINOR_NORM@_vapi_DEPS = gio-2.0
grilo_net_@GRL_MAJORMINOR_NORM@_vapi_METADATADIRS = $(srcdir)
grilo_net_@GRL_MAJORMINOR_NORM@_vapi_FILES = $(srcdir)/grilo-net-@GRL_MAJORMINOR@-custom.vala $(top_builddir)/libs/net/GrlNet-@GRL_MAJORMINOR@.gir

EXTRA_DIST += GrlNet-@GRL_MAJORMINOR@.metadata grilo-net-@GRL_MAJORMINOR@.deps grilo-net-@GRL_MAJORMINOR@-custom.vala

vapidir = $(datadir)/vala/vapi
vapi_DATA = $(VAPIGEN_VAPIS) $(VAPIGEN_VAPIS:.vapi=.deps)

CLEANFILES += $(vapi_DATA)

endif

-include $(top_srcdir)/git.mk
