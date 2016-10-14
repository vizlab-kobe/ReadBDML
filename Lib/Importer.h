#pragma once
#include <kvs/LineObject>
#include "BDMLData.h"


namespace ReadBDML
{

kvs::LineObject* ImportLineObjectBySequence( const ReadBDML::BDMLData& bdml, const size_t cindex, const size_t sindex );
kvs::LineObject* ImportLineObjectByComponent( const ReadBDML::BDMLData& bdml, const size_t cindex );
kvs::LineObject* ImportLineObjectByTime( const ReadBDML::BDMLData& bdml, const float time );

} // end of namespace ReadBDML
