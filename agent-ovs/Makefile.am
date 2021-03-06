#
# agent-ovs: Opflex agent for integrating Group-based policy with OVS
# Copyright (c) 2014 Cisco Systems, Inc. and others.  All rights reserved.
#
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License v1.0 which accompanies this distribution,
# and is available at http://www.eclipse.org/legal/epl-v10.html
#
###########
#
# Process this file with automake to produce a Makefile.in

ACLOCAL_AMFLAGS = -I m4

OVS_ADDL_CFLAGS = \
	-D__STDC_LIMIT_MACROS \
	-D__STDC_CONSTANT_MACROS \
	-fpermissive

AM_CPPFLAGS = $(BOOST_CPPFLAGS) \
	-I$(top_srcdir)/src/include \
	-DLOCALSTATEDIR='"$(localstatedir)"'

AM_LDFLAGS = $(BOOST_LDFLAGS)

noinst_LTLIBRARIES = libagent_ovs.la
libagent_ovs_la_CXXFLAGS = \
	$(libopflex_CFLAGS) \
	$(libmodelgbp_CFLAGS) \
	$(OVS_ADDL_CFLAGS) \
	$(libopenvswitch_CFLAGS) \
	$(libofproto_CFLAGS)
libagent_ovs_la_LIBADD = \
	$(libopflex_LIBS) \
	$(libmodelgbp_LIBS) \
	$(BOOST_SYSTEM_LIB) \
	$(BOOST_FILESYSTEM_LIB) \
	$(BOOST_THREAD_LIB) \
	$(BOOST_ASIO_LIB) \
	$(BOOST_RANDOM_LIB) \
	$(libopenvswitch_LIBS) \
	$(libofproto_LIBS)

noinst_HEADERS = \
	src/include/AgentLogHandler.h \
	src/include/PolicyListener.h \
	src/include/PolicyManager.h \
	src/include/Endpoint.h \
	src/include/EndpointListener.h \
	src/include/EndpointManager.h \
	src/include/EndpointSource.h \
	src/include/FSEndpointSource.h \
	src/include/Renderer.h \
	src/include/StitchedModeRenderer.h \
	src/include/TunnelEpManager.h \
	src/include/FlowExecutor.h \
	src/include/FlowReader.h \
	src/include/FlowManager.h \
	src/include/ovs.h \
	src/include/TableState.h \
	src/include/ActionBuilder.h \
	src/include/SwitchConnection.h \
	src/include/PortMapper.h \
	src/include/StatsManager.h \
	src/include/Agent.h \
	src/include/WorkQueue.h \
	src/include/IdGenerator.h \
	src/include/RangeMask.h \
	src/include/Packets.h \
	src/include/PacketInHandler.h \
	src/include/JsonCmdExecutor.h \
	src/include/AdvertManager.h \
	src/include/udp.h \
	src/include/dhcp.h \
	src/include/arp.h \
	src/include/cmd.h \
	src/include/logging.h

libagent_ovs_la_SOURCES = \
	src/AgentLogHandler.cpp \
	src/PolicyManager.cpp \
	src/Endpoint.cpp \
	src/EndpointManager.cpp \
	src/EndpointSource.cpp \
	src/FSEndpointSource.cpp \
	src/Renderer.cpp \
	src/StitchedModeRenderer.cpp \
	src/TunnelEpManager.cpp \
	src/FlowManager.cpp \
	src/TableState.cpp \
	src/FlowExecutor.cpp \
	src/FlowReader.cpp \
	src/ActionBuilder.cpp \
	src/SwitchConnection.cpp \
	src/PortMapper.cpp \
	src/StatsManager.cpp \
	src/cmd.cpp \
	src/logging.cpp \
	src/Agent.cpp \
	src/WorkQueue.cpp \
	src/IdGenerator.cpp \
	src/RangeMask.cpp \
	src/Packets.cpp \
	src/PacketInHandler.cpp \
	src/JsonCmdExecutor.cpp \
	src/AdvertManager.cpp

bin_PROGRAMS=agent_ovs gbp_inspect
agent_ovs_CXXFLAGS = -DSYSCONFDIR='"$(sysconfdir)"' $(OVS_ADDL_CFLAGS)
agent_ovs_SOURCES = \
	src/main.cpp
agent_ovs_LDADD = \
	libagent_ovs.la \
	$(BOOST_PROGRAM_OPTIONS_LIB)

gbp_inspect_CXXFLAGS = -DSYSCONFDIR='"$(sysconfdir)"'
gbp_inspect_SOURCES = \
	src/gbp_inspect.cpp
gbp_inspect_LDADD = \
	libagent_ovs.la \
	$(BOOST_IOSTREAMS_LIB) \
	$(BOOST_PROGRAM_OPTIONS_LIB)

TESTS = agent_test
noinst_PROGRAMS = $(TESTS) mock_server integration_test

agent_test_CXXFLAGS = \
	-I$(top_srcdir)/test/include \
	$(libopflex_CFLAGS) $(libmodelgbp_CFLAGS) \
	$(OVS_ADDL_CFLAGS) \
	$(libopenvswitch_CFLAGS) \
	$(libofproto_CFLAGS) \
	-DBOOST_TEST_DYN_LINK
agent_test_SOURCES = \
	test/include/BaseFixture.h \
	test/include/ModbFixture.h \
	test/include/MockSwitchConnection.h \
	test/include/MockPortMapper.h \
	test/PolicyManager_test.cpp \
	test/EndpointManager_test.cpp \
	test/FlowManager_test.cpp \
	test/PacketInHandler_test.cpp \
	test/AdvertManager_test.cpp \
	test/PortMapper_test.cpp \
	test/FlowExecutor_test.cpp \
	test/IdGenerator_test.cpp \
	test/RangeMask_test.cpp \
	test/Packets_test.cpp \
	test/JsonCmdExecutor_test.cpp \
	test/main.cpp
agent_test_LDADD = \
	libagent_ovs.la \
	$(BOOST_UNIT_TEST_FRAMEWORK_LIB) \
	$(libopenvswitch_LIBS) \
	$(libofproto_LIBS)

mock_server_CXXFLAGS = \
	-I$(top_srcdir)/test/include \
	$(libopflex_CFLAGS) $(libmodelgbp_CFLAGS) 
mock_server_SOURCES = \
	test/include/Policies.h \
	test/Policies.cpp \
	test/mock_server.cpp
mock_server_LDADD = \
	libagent_ovs.la \
	$(BOOST_PROGRAM_OPTIONS_LIB)

agentconfdir=$(sysconfdir)/opflex-agent-ovs
agentconf_DATA = opflex-agent-ovs.conf

flowidcachedir=${localstatedir}/lib/opflex-agent-ovs/ids
defwatchdir=${localstatedir}/lib/opflex-agent-ovs/endpoints
inspectsock=${localstatedir}/run/opflex-agent-ovs-inspect.sock
opflex-agent-ovs.conf: $(top_srcdir)/opflex-agent-ovs.conf.in
	sed -e "s|DEFAULT_FS_ENDPOINT_DIR|${defwatchdir}|" \
	    -e "s|DEFAULT_FLOWID_CACHE_DIR|${flowidcachedir}|" \
	    -e "s|DEFAULT_INSPECTOR_SOCKET|${inspectsock}|" \
	$(top_srcdir)/opflex-agent-ovs.conf.in > opflex-agent-ovs.conf

if HAVE_DOXYGEN
  noinst_DATA = \
	doc/html
endif

integration_test_CXXFLAGS = $(BOOST_CPPFLAGS) -DBOOST_TEST_DYN_LINK \
	-I$(top_srcdir)/integration-test/include \
	$(OVS_ADDL_CFLAGS)  \
	$(libopenvswitch_CFLAGS) \
	$(libofproto_CFLAGS)
integration_test_SOURCES = \
	integration-test/include/ConnectionFixture.h \
	integration-test/main.cpp \
	integration-test/connection_test.cpp \
	integration-test/flowmod_test.cpp
integration_test_LDFLAGS = $(BOOST_LDFLAGS)
integration_test_LDADD = \
	libagent_ovs.la \
	$(BOOST_UNIT_TEST_FRAMEWORK_LIB) \
	$(libopenvswitch_LIBS) \
	$(libofproto_LIBS)

check-integration: agent_ovs
	$(top_builddir)/integration_test
doc/html: $(model_include_HEADERS) $(noinst_HEADERS) doc/Doxyfile
	cd doc && ${DOXYGEN} Doxyfile
doc: doc/html

clean-doc:
	rm -rf doc/html doc/latex
clean-local: clean-doc
	rm -f *.rpm *.deb

EXTRA_DIST=rpm/agent-ovs.service rpm/90-agent-ovs-sysctl.conf opflex-agent-ovs.conf.in

CWD=`pwd`
RPMFLAGS=--define "_topdir ${CWD}/rpm"
ARCH=x86_64
SOURCE_FILE=${PACKAGE}-${VERSION}.tar.gz
RPMDIRS=rpm/BUILD rpm/SOURCES rpm/RPMS rpm/SRPMS
rpm: dist rpm/${PACKAGE}.spec
	mkdir -p ${RPMDIRS}
	cp ${SOURCE_FILE} rpm/SOURCES/
	rpmbuild ${RPMFLAGS} -ba rpm/${PACKAGE}.spec
	cp rpm/RPMS/${ARCH}/*.rpm .
	cp rpm/SRPMS/*.rpm .
	rm -rf ${RPMDIRS}
srpm: dist rpm/${PACKAGE}.spec
	mkdir -p ${RPMDIRS}
	cp ${SOURCE_FILE} rpm/SOURCES/
	rpmbuild ${RPMFLAGS} -bs rpm/${PACKAGE}.spec
	cp rpm/SRPMS/*.rpm .
	rm -rf ${RPMDIRS}

EXTRA_DIST += debian

# Set env var DEB_BUILD_OPTIONS="parallel=<#cores>" to speed up package builds
DEB_PKG_DIR=deb
deb: dist
	- rm -rf  $(DEB_PKG_DIR)
	mkdir -p $(DEB_PKG_DIR)
	cp $(SOURCE_FILE) $(DEB_PKG_DIR)/
	tar -C $(DEB_PKG_DIR)/ -xf $(DEB_PKG_DIR)/$(SOURCE_FILE)
	mv $(DEB_PKG_DIR)/$(SOURCE_FILE) $(DEB_PKG_DIR)/$(PACKAGE)_$(VERSION).orig.tar.gz
	cd $(DEB_PKG_DIR)/$(PACKAGE)-$(VERSION)/; \
		VERSION_WITH_BUILD=$(VERSION)-$(BVERSION) \
		dpkg-buildpackage -d -us -uc -rfakeroot -b
	cp $(DEB_PKG_DIR)/*.deb .
	rm -rf $(DEB_PKG_DIR)
