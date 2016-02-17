/*****************************************************************************/
/**
 *  @file   BDML.h
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

#include <string>
#include "BDMLTag.h"
#include "InfoTag.h"
#include "DataTag.h"


namespace kvs_ext
{

class BDMLData
{
    bdml::BDMLTag m_bdml;

public:
    bdml::InfoTag info;
    bdml::DataTag data;

    BDMLData() {}
    BDMLData( const std::string& filename );

    bool read( const std::string& filename );
};

} // end of namespace kvs_ext
