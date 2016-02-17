/*****************************************************************************/
/**
 *  @file   Tag.h
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

#include "XML.h"
#include <string>


namespace kvs_ext
{

namespace bdml
{

class Tag
{
private:
    std::string m_name;
    Node* m_node;

public:
    explicit Tag( const std::string& name );
    Tag( const Node* parent, const std::string& name );

    const std::string& name() const { return m_name; }
    Node* node() { return m_node; }
    const Node* node() const { return m_node; }
    bool read( const Node* parent );

private:
    Tag();
};

} // end of namespace bdml

} // end of namespace kvs_ext
