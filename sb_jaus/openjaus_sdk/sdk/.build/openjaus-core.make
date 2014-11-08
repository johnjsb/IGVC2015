# GNU Make project makefile autogenerated by Premake
ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifeq ($(config),debug)
  OBJDIR     = Debug/openjaus-core
  TARGETDIR  = ../lib
  TARGET     = $(TARGETDIR)/libopenjaus-core.so
  DEFINES   += -DDEBUG
  INCLUDES  += -I../include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -Wall -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -shared -L../lib
  LIBS      += -ljson -lopenjaus -lpthread -lrt
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += ../lib/libjson.so ../lib/libopenjaus.so
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release)
  OBJDIR     = Release/openjaus-core
  TARGETDIR  = ../lib
  TARGET     = $(TARGETDIR)/libopenjaus-core.so
  DEFINES   += -DNDEBUG
  INCLUDES  += -I../include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -shared -L../lib
  LIBS      += -ljson -lopenjaus -lpthread -lrt
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += ../lib/libjson.so ../lib/libopenjaus.so
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/Base.o \
	$(OBJDIR)/Events.o \
	$(OBJDIR)/Transport.o \
	$(OBJDIR)/Managed.o \
	$(OBJDIR)/AccessControlled.o \
	$(OBJDIR)/ShutdownTransition.o \
	$(OBJDIR)/ResetTransition.o \
	$(OBJDIR)/Pause.o \
	$(OBJDIR)/ManagementLoopback.o \
	$(OBJDIR)/PushToEmergency.o \
	$(OBJDIR)/DefaultConfigurationLoop.o \
	$(OBJDIR)/TimeControlledLoop.o \
	$(OBJDIR)/InitializedTransition.o \
	$(OBJDIR)/HeartbeatLoop.o \
	$(OBJDIR)/TimeDefaultLoop.o \
	$(OBJDIR)/ControlledLoopback.o \
	$(OBJDIR)/EventsLoop.o \
	$(OBJDIR)/DiscoveryLoopback.o \
	$(OBJDIR)/PolicyLoop.o \
	$(OBJDIR)/NotControlledLoopback.o \
	$(OBJDIR)/PopFromEmergency.o \
	$(OBJDIR)/AcceptControlTransition.o \
	$(OBJDIR)/DefaultStateLoop.o \
	$(OBJDIR)/ToReady.o \
	$(OBJDIR)/ReleaseControlTransition.o \
	$(OBJDIR)/QueryJausAddress.o \
	$(OBJDIR)/SetEmergency.o \
	$(OBJDIR)/ReportServices.o \
	$(OBJDIR)/QueryIdentification.o \
	$(OBJDIR)/RegisterServices.o \
	$(OBJDIR)/RejectEventRequest.o \
	$(OBJDIR)/ReleaseControl.o \
	$(OBJDIR)/Event.o \
	$(OBJDIR)/ReportTransportPolicy.o \
	$(OBJDIR)/QueryServices.o \
	$(OBJDIR)/QueryTimeout.o \
	$(OBJDIR)/CommandEvent.o \
	$(OBJDIR)/QueryHeartbeatPulse.o \
	$(OBJDIR)/RejectControl.o \
	$(OBJDIR)/QueryEventTimeout.o \
	$(OBJDIR)/ReportSubsystemList.o \
	$(OBJDIR)/Reset.o \
	$(OBJDIR)/ReportEvents.o \
	$(OBJDIR)/ReportIdentification.o \
	$(OBJDIR)/Resume.o \
	$(OBJDIR)/ReportTime.o \
	$(OBJDIR)/ReportServiceList.o \
	$(OBJDIR)/QueryControl.o \
	$(OBJDIR)/QueryTime.o \
	$(OBJDIR)/UpdateEvent.o \
	$(OBJDIR)/Receive.o \
	$(OBJDIR)/QueryAuthority.o \
	$(OBJDIR)/ConfirmEventRequest.o \
	$(OBJDIR)/CreateCommandEvent.o \
	$(OBJDIR)/ReportTimeout.o \
	$(OBJDIR)/Initialized.o \
	$(OBJDIR)/QueryServiceList.o \
	$(OBJDIR)/ReportControl.o \
	$(OBJDIR)/ReportJausAddress.o \
	$(OBJDIR)/ConfirmControl.o \
	$(OBJDIR)/ReportHeartbeatPulse.o \
	$(OBJDIR)/QueryConfiguration.o \
	$(OBJDIR)/Send.o \
	$(OBJDIR)/SetTime.o \
	$(OBJDIR)/QueryEvents.o \
	$(OBJDIR)/SetAuthority.o \
	$(OBJDIR)/Shutdown.o \
	$(OBJDIR)/RequestControl.o \
	$(OBJDIR)/ReportConfiguration.o \
	$(OBJDIR)/QuerySubsystemList.o \
	$(OBJDIR)/ReportStatus.o \
	$(OBJDIR)/ReportEventTimeout.o \
	$(OBJDIR)/QueryStatus.o \
	$(OBJDIR)/ClearEmergency.o \
	$(OBJDIR)/CreateEvent.o \
	$(OBJDIR)/ReportAuthority.o \
	$(OBJDIR)/CancelEvent.o \
	$(OBJDIR)/Standby.o \
	$(OBJDIR)/QueryTransportPolicy.o \
	$(OBJDIR)/EmergencyCodeEnumeration.o \
	$(OBJDIR)/DateBitField.o \
	$(OBJDIR)/ServicesComponentRecord.o \
	$(OBJDIR)/ServiceList.o \
	$(OBJDIR)/QueryEventsVariant.o \
	$(OBJDIR)/ServicesServiceList.o \
	$(OBJDIR)/QSLComponentList.o \
	$(OBJDIR)/TimeRecord.o \
	$(OBJDIR)/PreferenceTCPEnumeration.o \
	$(OBJDIR)/QSLSubsystemList.o \
	$(OBJDIR)/AddressBitField.o \
	$(OBJDIR)/SystemLevelEnumeration.o \
	$(OBJDIR)/QSNodeRecord.o \
	$(OBJDIR)/ConfigurationComponentList.o \
	$(OBJDIR)/QSLSubsystemRecord.o \
	$(OBJDIR)/PeriodicRateScaledInteger.o \
	$(OBJDIR)/QSLComponentRecord.o \
	$(OBJDIR)/ServicesComponentList.o \
	$(OBJDIR)/ReportEventRecord.o \
	$(OBJDIR)/ServicesNodeList.o \
	$(OBJDIR)/QSNodeList.o \
	$(OBJDIR)/RSubsystemRecord.o \
	$(OBJDIR)/ConfigurationNodeRecord.o \
	$(OBJDIR)/StatusEnumeration.o \
	$(OBJDIR)/ConfirmResponseCodeEnumeration.o \
	$(OBJDIR)/QSComponentList.o \
	$(OBJDIR)/QSLNodeRecord.o \
	$(OBJDIR)/ConfigurationComponentRecord.o \
	$(OBJDIR)/ServicesNodeRecord.o \
	$(OBJDIR)/RSLSubsystemRecord.o \
	$(OBJDIR)/ServiceInformationRecord.o \
	$(OBJDIR)/RejectResponseCodeEnumeration.o \
	$(OBJDIR)/ConfigurationNodeList.o \
	$(OBJDIR)/ResponseCodeEnumeration.o \
	$(OBJDIR)/RSubsystemList.o \
	$(OBJDIR)/TimeBitField.o \
	$(OBJDIR)/CommandResultEnumeration.o \
	$(OBJDIR)/QSLNodeList.o \
	$(OBJDIR)/EventList.o \
	$(OBJDIR)/EventTypeEnumeration.o \
	$(OBJDIR)/SourceIDBitField.o \
	$(OBJDIR)/RSLSubsystemList.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking openjaus-core
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning openjaus-core
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
	-$(SILENT) cp $< $(OBJDIR)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
endif

$(OBJDIR)/Base.o: ../src/openjaus/core/Base.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Events.o: ../src/openjaus/core/Events.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Transport.o: ../src/openjaus/core/Transport.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Managed.o: ../src/openjaus/core/Managed.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/AccessControlled.o: ../src/openjaus/core/AccessControlled.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ShutdownTransition.o: ../src/openjaus/core/Transitions/ShutdownTransition.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ResetTransition.o: ../src/openjaus/core/Transitions/ResetTransition.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Pause.o: ../src/openjaus/core/Transitions/Pause.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ManagementLoopback.o: ../src/openjaus/core/Transitions/ManagementLoopback.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/PushToEmergency.o: ../src/openjaus/core/Transitions/PushToEmergency.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/DefaultConfigurationLoop.o: ../src/openjaus/core/Transitions/DefaultConfigurationLoop.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/TimeControlledLoop.o: ../src/openjaus/core/Transitions/TimeControlledLoop.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/InitializedTransition.o: ../src/openjaus/core/Transitions/InitializedTransition.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/HeartbeatLoop.o: ../src/openjaus/core/Transitions/HeartbeatLoop.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/TimeDefaultLoop.o: ../src/openjaus/core/Transitions/TimeDefaultLoop.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ControlledLoopback.o: ../src/openjaus/core/Transitions/ControlledLoopback.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/EventsLoop.o: ../src/openjaus/core/Transitions/EventsLoop.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/DiscoveryLoopback.o: ../src/openjaus/core/Transitions/DiscoveryLoopback.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/PolicyLoop.o: ../src/openjaus/core/Transitions/PolicyLoop.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/NotControlledLoopback.o: ../src/openjaus/core/Transitions/NotControlledLoopback.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/PopFromEmergency.o: ../src/openjaus/core/Transitions/PopFromEmergency.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/AcceptControlTransition.o: ../src/openjaus/core/Transitions/AcceptControlTransition.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/DefaultStateLoop.o: ../src/openjaus/core/Transitions/DefaultStateLoop.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ToReady.o: ../src/openjaus/core/Transitions/ToReady.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReleaseControlTransition.o: ../src/openjaus/core/Transitions/ReleaseControlTransition.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryJausAddress.o: ../src/openjaus/core/Triggers/QueryJausAddress.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SetEmergency.o: ../src/openjaus/core/Triggers/SetEmergency.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportServices.o: ../src/openjaus/core/Triggers/ReportServices.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryIdentification.o: ../src/openjaus/core/Triggers/QueryIdentification.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RegisterServices.o: ../src/openjaus/core/Triggers/RegisterServices.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RejectEventRequest.o: ../src/openjaus/core/Triggers/RejectEventRequest.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReleaseControl.o: ../src/openjaus/core/Triggers/ReleaseControl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Event.o: ../src/openjaus/core/Triggers/Event.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportTransportPolicy.o: ../src/openjaus/core/Triggers/ReportTransportPolicy.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryServices.o: ../src/openjaus/core/Triggers/QueryServices.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryTimeout.o: ../src/openjaus/core/Triggers/QueryTimeout.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CommandEvent.o: ../src/openjaus/core/Triggers/CommandEvent.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryHeartbeatPulse.o: ../src/openjaus/core/Triggers/QueryHeartbeatPulse.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RejectControl.o: ../src/openjaus/core/Triggers/RejectControl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryEventTimeout.o: ../src/openjaus/core/Triggers/QueryEventTimeout.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportSubsystemList.o: ../src/openjaus/core/Triggers/ReportSubsystemList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Reset.o: ../src/openjaus/core/Triggers/Reset.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportEvents.o: ../src/openjaus/core/Triggers/ReportEvents.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportIdentification.o: ../src/openjaus/core/Triggers/ReportIdentification.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Resume.o: ../src/openjaus/core/Triggers/Resume.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportTime.o: ../src/openjaus/core/Triggers/ReportTime.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportServiceList.o: ../src/openjaus/core/Triggers/ReportServiceList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryControl.o: ../src/openjaus/core/Triggers/QueryControl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryTime.o: ../src/openjaus/core/Triggers/QueryTime.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/UpdateEvent.o: ../src/openjaus/core/Triggers/UpdateEvent.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Receive.o: ../src/openjaus/core/Triggers/Receive.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryAuthority.o: ../src/openjaus/core/Triggers/QueryAuthority.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ConfirmEventRequest.o: ../src/openjaus/core/Triggers/ConfirmEventRequest.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CreateCommandEvent.o: ../src/openjaus/core/Triggers/CreateCommandEvent.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportTimeout.o: ../src/openjaus/core/Triggers/ReportTimeout.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Initialized.o: ../src/openjaus/core/Triggers/Initialized.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryServiceList.o: ../src/openjaus/core/Triggers/QueryServiceList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportControl.o: ../src/openjaus/core/Triggers/ReportControl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportJausAddress.o: ../src/openjaus/core/Triggers/ReportJausAddress.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ConfirmControl.o: ../src/openjaus/core/Triggers/ConfirmControl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportHeartbeatPulse.o: ../src/openjaus/core/Triggers/ReportHeartbeatPulse.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryConfiguration.o: ../src/openjaus/core/Triggers/QueryConfiguration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Send.o: ../src/openjaus/core/Triggers/Send.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SetTime.o: ../src/openjaus/core/Triggers/SetTime.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryEvents.o: ../src/openjaus/core/Triggers/QueryEvents.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SetAuthority.o: ../src/openjaus/core/Triggers/SetAuthority.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Shutdown.o: ../src/openjaus/core/Triggers/Shutdown.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RequestControl.o: ../src/openjaus/core/Triggers/RequestControl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportConfiguration.o: ../src/openjaus/core/Triggers/ReportConfiguration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QuerySubsystemList.o: ../src/openjaus/core/Triggers/QuerySubsystemList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportStatus.o: ../src/openjaus/core/Triggers/ReportStatus.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportEventTimeout.o: ../src/openjaus/core/Triggers/ReportEventTimeout.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryStatus.o: ../src/openjaus/core/Triggers/QueryStatus.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ClearEmergency.o: ../src/openjaus/core/Triggers/ClearEmergency.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CreateEvent.o: ../src/openjaus/core/Triggers/CreateEvent.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportAuthority.o: ../src/openjaus/core/Triggers/ReportAuthority.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CancelEvent.o: ../src/openjaus/core/Triggers/CancelEvent.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Standby.o: ../src/openjaus/core/Triggers/Standby.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryTransportPolicy.o: ../src/openjaus/core/Triggers/QueryTransportPolicy.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/EmergencyCodeEnumeration.o: ../src/openjaus/core/Triggers/Fields/EmergencyCodeEnumeration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/DateBitField.o: ../src/openjaus/core/Triggers/Fields/DateBitField.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ServicesComponentRecord.o: ../src/openjaus/core/Triggers/Fields/ServicesComponentRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ServiceList.o: ../src/openjaus/core/Triggers/Fields/ServiceList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QueryEventsVariant.o: ../src/openjaus/core/Triggers/Fields/QueryEventsVariant.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ServicesServiceList.o: ../src/openjaus/core/Triggers/Fields/ServicesServiceList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QSLComponentList.o: ../src/openjaus/core/Triggers/Fields/QSLComponentList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/TimeRecord.o: ../src/openjaus/core/Triggers/Fields/TimeRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/PreferenceTCPEnumeration.o: ../src/openjaus/core/Triggers/Fields/PreferenceTCPEnumeration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QSLSubsystemList.o: ../src/openjaus/core/Triggers/Fields/QSLSubsystemList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/AddressBitField.o: ../src/openjaus/core/Triggers/Fields/AddressBitField.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SystemLevelEnumeration.o: ../src/openjaus/core/Triggers/Fields/SystemLevelEnumeration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QSNodeRecord.o: ../src/openjaus/core/Triggers/Fields/QSNodeRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ConfigurationComponentList.o: ../src/openjaus/core/Triggers/Fields/ConfigurationComponentList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QSLSubsystemRecord.o: ../src/openjaus/core/Triggers/Fields/QSLSubsystemRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/PeriodicRateScaledInteger.o: ../src/openjaus/core/Triggers/Fields/PeriodicRateScaledInteger.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QSLComponentRecord.o: ../src/openjaus/core/Triggers/Fields/QSLComponentRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ServicesComponentList.o: ../src/openjaus/core/Triggers/Fields/ServicesComponentList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ReportEventRecord.o: ../src/openjaus/core/Triggers/Fields/ReportEventRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ServicesNodeList.o: ../src/openjaus/core/Triggers/Fields/ServicesNodeList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QSNodeList.o: ../src/openjaus/core/Triggers/Fields/QSNodeList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RSubsystemRecord.o: ../src/openjaus/core/Triggers/Fields/RSubsystemRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ConfigurationNodeRecord.o: ../src/openjaus/core/Triggers/Fields/ConfigurationNodeRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/StatusEnumeration.o: ../src/openjaus/core/Triggers/Fields/StatusEnumeration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ConfirmResponseCodeEnumeration.o: ../src/openjaus/core/Triggers/Fields/ConfirmResponseCodeEnumeration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QSComponentList.o: ../src/openjaus/core/Triggers/Fields/QSComponentList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QSLNodeRecord.o: ../src/openjaus/core/Triggers/Fields/QSLNodeRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ConfigurationComponentRecord.o: ../src/openjaus/core/Triggers/Fields/ConfigurationComponentRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ServicesNodeRecord.o: ../src/openjaus/core/Triggers/Fields/ServicesNodeRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RSLSubsystemRecord.o: ../src/openjaus/core/Triggers/Fields/RSLSubsystemRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ServiceInformationRecord.o: ../src/openjaus/core/Triggers/Fields/ServiceInformationRecord.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RejectResponseCodeEnumeration.o: ../src/openjaus/core/Triggers/Fields/RejectResponseCodeEnumeration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ConfigurationNodeList.o: ../src/openjaus/core/Triggers/Fields/ConfigurationNodeList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ResponseCodeEnumeration.o: ../src/openjaus/core/Triggers/Fields/ResponseCodeEnumeration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RSubsystemList.o: ../src/openjaus/core/Triggers/Fields/RSubsystemList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/TimeBitField.o: ../src/openjaus/core/Triggers/Fields/TimeBitField.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CommandResultEnumeration.o: ../src/openjaus/core/Triggers/Fields/CommandResultEnumeration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/QSLNodeList.o: ../src/openjaus/core/Triggers/Fields/QSLNodeList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/EventList.o: ../src/openjaus/core/Triggers/Fields/EventList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/EventTypeEnumeration.o: ../src/openjaus/core/Triggers/Fields/EventTypeEnumeration.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SourceIDBitField.o: ../src/openjaus/core/Triggers/Fields/SourceIDBitField.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/RSLSubsystemList.o: ../src/openjaus/core/Triggers/Fields/RSLSubsystemList.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
