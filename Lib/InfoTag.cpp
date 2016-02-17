/*****************************************************************************/
/**
 *  @file   InfoTag.cpp
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
#include "InfoTag.h"
#include "XML.h"


namespace kvs_ext
{

namespace bdml
{

InfoTag::InfoTag() : Tag("info")
{
    bdmlID = "";
    title = "";
    license = "";
    release = "";
    version = 0;
}

bool InfoTag::read( const Node* parent )
{
    if ( !Tag::read( parent ) ) { return false; }

    Tag bdmlID_tag("bdmlID");
    if ( bdmlID_tag.read( this->node() ) ) { bdmlID = NodeValue<std::string>( bdmlID_tag.node() ); }

    Tag title_tag("title");
    if ( title_tag.read( this->node() ) ) { title = NodeValue<std::string>( title_tag.node() ); }

    Tag license_tag("license");
    if ( license_tag.read( this->node() ) ) { license = NodeValue<std::string>( license_tag.node() ); }

    Tag release_tag("release");
    if ( release_tag.read( this->node() ) ) { release = NodeValue<std::string>( release_tag.node() ); }

    Tag version_tag("version");
    if ( version_tag.read( this->node() ) ) { version = NodeValue<float>( version_tag.node() ); }

    return true;
}

} // end of namespace bdml

} // end of namespace kvs_ext
