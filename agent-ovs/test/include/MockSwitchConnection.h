/* -*- C++ -*-; c-basic-offset: 4; indent-tabs-mode: nil */
/*
 * Copyright (c) 2014 Cisco Systems, Inc. and others.  All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v1.0 which accompanies this distribution,
 * and is available at http://www.eclipse.org/legal/epl-v10.html
 */

#ifndef OVSAGENT_TEST_MOCKSWITCHCONNECTION_H_
#define OVSAGENT_TEST_MOCKSWITCHCONNECTION_H_

#include "SwitchConnection.h"

/**
 * Mock switch connection object useful for tests
 */
class MockSwitchConnection : public SwitchConnection {
public:
    MockSwitchConnection()
        : SwitchConnection("mockBridge"), connected(false) {
    }
    virtual ~MockSwitchConnection() {
        clear();
    }

    virtual void clear() {
        BOOST_FOREACH(ofpbuf* msg, sentMsgs) {
            ofpbuf_delete(msg);
        }
        sentMsgs.clear();
    }

    virtual ofp_version GetProtocolVersion() { return OFP13_VERSION; }

    virtual int SendMessage(ofpbuf *msg) {
        sentMsgs.push_back(msg);
        return 0;
    }

    virtual bool IsConnected() { return connected; }

    bool connected;
    std::vector<ofpbuf*> sentMsgs;
};

#endif /* OVSAGENT_TEST_MOCKSWITCHCONNECTION_H_ */
