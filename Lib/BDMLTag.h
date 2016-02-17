/*****************************************************************************/
/**
 *  @file   BDMLTag.h
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


namespace kvs_ext
{

namespace bdml
{

struct BDMLTag : public Tag
{
    float version;

    BDMLTag();

    bool read( const Node* parent );
};

} // end of namespace bdml

} // end of namespace kvs_ext
