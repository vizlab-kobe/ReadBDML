/*****************************************************************************/
/**
 *  @file   MeasurementTag.h
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
#include "LineTag.h"
#include <string>
#include <iostream>
#include <kvs/Indent>


namespace kvs_ext
{

namespace bdml
{

/*===========================================================================*/
/**
 *  @brief  Measurement tag class.
 */
/*===========================================================================*/
class MeasurementTag : public Tag
{
private:
    std::string m_objectRef; ///< reference to the object
    LineTag m_line; ///< line entity

public:
    MeasurementTag();

    const std::string& objectRef() const { return m_objectRef; }
    const LineTag& line() const { return m_line; }

    void print( std::ostream& os, const kvs::Indent& indent = kvs::Indent(0) ) const;
    bool read( const Node* parent );
};

} // end of namespace bdml

} // end of namespace kvs_ext
