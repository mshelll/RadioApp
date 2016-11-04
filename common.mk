# This is an automatically generated record.
# The area between QNX Internal Start and QNX Internal End is controlled by
# the QNX IDE properties.

ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

#===== USEFILE - the file containing the usage message for the application. 
USEFILE=

# Next lines are for C++ projects only

EXTRA_SUFFIXES+=cxx cpp

VFLAG_g=-gstabs+

#===== EXTRA_INCVPATH - a space-separated list of directories to search for include files.
EXTRA_INCVPATH+=$(PROJECT_ROOT)/src  \
	D:/QNX_ide-4.7-workspace/Boost/release/target/qnx6/armle-v7/include

#===== EXTRA_SRCVPATH - a space-separated list of directories to search for source files.
EXTRA_SRCVPATH+=$(PROJECT_ROOT)/src  \
	$(PROJECT_ROOT)/src/Message $(PROJECT_ROOT)/src/Protocol  \
	$(PROJECT_ROOT)/src/Protocol/Request  \
	$(PROJECT_ROOT)/src/Protocol/Response  \
	$(PROJECT_ROOT)/src/ahaBinaryInterface  \
	$(PROJECT_ROOT)/src/ahaBinaryInterface/CommandAPIs  \
	$(PROJECT_ROOT)/src/Connector $(PROJECT_ROOT)/src/Factory  \
	$(PROJECT_ROOT)/src/Utility  \
	$(PROJECT_ROOT)/src/Presentation  \
	$(PROJECT_ROOT)/src/Presentation/Command  \
	$(PROJECT_ROOT)/src/Presentation/Entity
	
#===== EXTRA_LIBVPATH - a space-separated list of directories to search for library files.
EXTRA_LIBVPATH+=D:/QNX_ide-4.7-workspace/Boost/release/target/qnx6/armle-v7/lib/  \
	D:/QNX_ide-4.7-workspace/Boost/release/target/qnx6/$(CPU)$(VARIANT)/lib/  \
	D:/QNX_ide-4.7-workspace/Boost/release/target/qnx6/$(CPU)$(VARIANT)/lib

#===== CCFLAGS - add the flags to the C compiler command line. 
CCFLAGS+=-Wno-psabi

#===== LIBS - a space-separated list of library items to be included in the link.
LIBS+=-Bstatic boost_system boost_thread -Bdynamic

#===== LDFLAGS - add the flags to the linker command line.
LDFLAGS+=-lang-c++

include $(MKFILES_ROOT)/qmacros.mk
ifndef QNX_INTERNAL
QNX_INTERNAL=$(PROJECT_ROOT)/.qnx_internal.mk
endif
include $(QNX_INTERNAL)

include $(MKFILES_ROOT)/qtargets.mk

OPTIMIZE_TYPE_g=none
OPTIMIZE_TYPE=$(OPTIMIZE_TYPE_$(filter g, $(VARIANTS)))

