/*****************************************************************************/
/**
 *  @file   DataTag.h
 *  @author Naohisa Sakamoto
 */
/*----------------------------------------------------------------------------
 *
 *  Copyright (c) Visualization Laboratory, Kyoto University.
 *  All rights reserved.
 *  See http://www.viz.media.kyoto-u.ac.jp/kvs/copyright/ for details.
 *
 *  $Id$
 */
/*****************************************************************************/
#pragma once

#include "Tag.h"
#include "ScaleUnitTag.h"
#include "ComponentTag.h"
#include <vector>
#include <iostream>
#include <kvs/Indent>


namespace ReadBDML
{

namespace bdml
{

/*===========================================================================*/
/**
 *  @brief  Data tag class.
 */
/*===========================================================================*/
class DataTag : public Tag
{
private:
    ScaleUnitTag m_scale_unit; ///< scales and measurement units
    std::vector<ComponentTag> m_components; ///< collection of the objects

public:

    DataTag();

    const ScaleUnitTag& scaleUnit() const { return m_scale_unit; }
    const std::vector<ComponentTag>& components() const { return m_components; }
    const ComponentTag& component( const size_t index ) const { return m_components[index]; }

    void print( std::ostream& os, const kvs::Indent& indent = kvs::Indent(0) ) const;
    bool read( const Node* parent );
};

} // end of namespace bdml

} // end of namespace ReadBDML
