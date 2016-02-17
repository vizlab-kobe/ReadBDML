/*****************************************************************************/
/**
 *  @file   InfoTag.h
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
#include <string>


namespace kvs_ext
{

namespace bdml
{

struct InfoTag : public Tag
{
    std::string bdmlID;
    std::string title;
    std::string license;
    std::string release;
    float version;

    InfoTag();

    bool read( const Node* parent );
};

} // end of namespace bdml

} // end of namespace kvs_ext
