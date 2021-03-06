/* -*- C++ -*-; c-basic-offset: 4; indent-tabs-mode: nil */
/*!
 * @file PropertyInfo.h
 * @brief Interface definition file for PropertyInfo
 */
/*
 * Copyright (c) 2014 Cisco Systems, Inc. and others.  All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v1.0 which accompanies this distribution,
 * and is available at http://www.eclipse.org/legal/epl-v10.html
 */

#ifndef MODB_PROPERTYINFO_H
#define MODB_PROPERTYINFO_H

#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <string>

#include "opflex/modb/EnumInfo.h"

namespace opflex {
namespace modb {

/**
 * \addtogroup cpp
 * @{
 * \addtogroup metadata
 * @{
 */

/**
 * A unique class ID
 */
typedef uint64_t class_id_t;

/**
 * A unique property ID
 */
typedef uint64_t prop_id_t;
 
/**
 * @brief Property info provides metadata about a particular managed object
 * property.
 * 
 * This metadata is generated by the code generation framework and is
 * required when the framework is initialized.
 */
class PropertyInfo {
public:
   
    /**
     * Possible property types
     */
    enum property_type_t {
        /** A composite property */
        COMPOSITE,
        /** A string-valued property containing a class ID and URI
            which is a reference to another location in the management
            information tree. */
        REFERENCE,
        /** A string-valued property */
        STRING,
        /** A signed 64-bit integer value */
        S64,
        /** An unsigned 64-bit integer value */
        U64,
        /** A MAC address */
        MAC,
        /** An 8-bit enum value */
        ENUM8,
        /** A 16-bit enum value */
        ENUM16,
        /** A 32-bit enum value */
        ENUM32,
        /** A 64-bit enum value */
        ENUM64
    };
    
    /**
     * Enum representing the cardinality of the property
     */
    enum cardinality_t {
        /** A scalar-valued property */
        SCALAR,
        /** A vector-valued property */
        VECTOR
    };

    /**
     * Default constructor
     */
    PropertyInfo() {}
    
    /**
     * Construct a property info object with the provided property
     * name and primitive property type.
     */
    PropertyInfo(prop_id_t prop_id,
                 const std::string& property_name, 
                 property_type_t type,
                 cardinality_t cardinality);

    /**
     * Construct a property info object with enum info of the specified type.
     */
    PropertyInfo(prop_id_t prop_id,
                 const std::string& property_name,
                 property_type_t type,
                 cardinality_t cardinality,
                 const EnumInfo& enum_info);

    /**
     * Construct a property info object with either a composite or
     * reference data type of the specified type.
     */
    PropertyInfo(prop_id_t prop_id,
                 const std::string& property_name, 
                 property_type_t type,
                 class_id_t class_id,
                 cardinality_t cardinality);

    /**
     * Destroy the property info object
     */
    ~PropertyInfo();

    /**
     * Get the id for this property
     */
    prop_id_t getId() const { return prop_id; }

    /**
     * Get the name for this property
     */
    const std::string& getName() const { return property_name; }
    
    /**
     * Get the type of this property
     */
    const property_type_t getType() const { return prop_type; }

    /**
     * Get the class ID for this property.  This is valid only when
     * property_type_t == COMPOSITE
     */
    const class_id_t getClassId() const { return class_id; }

    /**
     * Get the cardinality for this type.
     */
    const cardinality_t getCardinality() const { return cardinality; }

    /**
     * Get the associated enum info for this property if it is an enum.
     */
    const EnumInfo& getEnumInfo() const { return enum_info; }

private:
    /**
     * The property ID for this property
     */
    prop_id_t prop_id;

    /**
     * The name for this property
     */
    std::string property_name;

    /**
     * The type of this property
     */
    property_type_t prop_type;

    /**
     * The class ID for this property if its a composite type.  If
     * prop_type is set to COMPOSITE, then this value must be set.
     */
    class_id_t class_id;

    /**
     * The cardinality of the provided property
     */
    cardinality_t cardinality;

    /**
     * Associated enum info if this property is an enum type.
     */
    EnumInfo enum_info;
};

/* @} metadata */
/* @} cpp */

} /* namespace modb */
} /* namespace opflex */

#endif /* MODB_PROPERTYINFO_H */
