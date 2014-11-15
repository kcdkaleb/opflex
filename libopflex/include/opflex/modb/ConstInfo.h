/* -*- C++ -*-; c-basic-offset: 4; indent-tabs-mode: nil */
/*!
 * @file ConstInfo.h
 * @brief Interface definition file for ConstInfo
 */
/*
 * Copyright (c) 2014 Cisco Systems, Inc. and others.  All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v1.0 which accompanies this distribution,
 * and is available at http://www.eclipse.org/legal/epl-v10.html
 */

#ifndef MODB_CONSTINFO_H
#define MODB_CONSTINFO_H

#include <string>
#include <boost/cstdint.hpp>

namespace opflex {
namespace modb {

/**
 * \addtogroup cpp
 * @{
 * \addtogroup metadata
 * @{
 */

/**
 * @brief Const info defines a specific enum member.
 *
 * This metadata is generated by the code generation framework and is
 * required when the framework is initialized.
 */
class ConstInfo {
public:

    /**
     * Construct a const info object with the given name and ID.
     */
    ConstInfo(const std::string &name_,
              uint64_t id_)
        : name(name_), id(id_) {}

    /**
     * Destructor
     */
    ~ConstInfo() {}

    /**
     * Get the name for this const. This value is used
     * to represent this const in JSON documents.
     * @return the const name
     */
    const std::string& getName() const { return name; }

    /**
     * Get the unique ID for this const within the enclosing enum.
     * @return the const ID within the enum
     */
    const uint64_t getId() const { return id; }

private:
    /**
     * The name for this const
     */
    std::string name;

    /**
     * The unique ID for this const within the enclosing enum
     */
    uint64_t id;
};

/* @} metadata */
/* @} cpp */

} /* namespace modb */
} /* namespace opflex */

#endif
