/* -*- C++ -*-; c-basic-offset: 4; indent-tabs-mode: nil */
/*
 * Include file for policy listener
 *
 * Copyright (c) 2014 Cisco Systems, Inc. and others.  All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v1.0 which accompanies this distribution,
 * and is available at http://www.eclipse.org/legal/epl-v10.html
 */

#include <opflex/modb/URI.h>
#include <opflex/modb/PropertyInfo.h>

#pragma once
#ifndef OVSAGENT_POLICYLISTENER_H
#define OVSAGENT_POLICYLISTENER_H

namespace ovsagent {

/**
 * An abstract interface for classes interested in updates related to
 * the policy and the indices.
 */
class PolicyListener {
public:
    /**
     * Destroy the policy listener and clean up all state
     */
    virtual ~PolicyListener() {};

    /**
     * Called when the forwarding domains for an endpoint group have
     * been updated.
     */
    virtual void egDomainUpdated(const opflex::modb::URI& egURI) {};

    /**
     * Called when a forwarding domain object is updated.
     */
    virtual void domainUpdated(opflex::modb::class_id_t cid,
                               const opflex::modb::URI& domURI) {}

    /**
     * Called when a policy contract is updated. These include changes to
     * the rules that comprise the contract as well as changes to the list
     * of provider/consumer endpoint groups for the contract.
     */
    virtual void contractUpdated(const opflex::modb::URI& contractURI) {}

    /**
     * Called when the platform config object is updated
     */
    virtual void configUpdated(const opflex::modb::URI& configURI) {}
};

} /* namespace ovsagent */

#endif /* OVSAGENT_POLICYMANAGER_H */
