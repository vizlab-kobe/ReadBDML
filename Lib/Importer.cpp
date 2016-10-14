#include "Importer.h"
#include <kvs/Vector3>
#include <kvs/RGBColor>
#include <kvs/ValueArray>
#include <vector>


namespace ReadBDML
{

kvs::LineObject* ImportLineObjectBySequence( const ReadBDML::BDMLData& bdml, const size_t cindex, const size_t sindex )
{
    kvs::LineObject* object = new kvs::LineObject();

    const ReadBDML::bdml::ComponentTag& component = bdml.data().component(cindex);
    const ReadBDML::bdml::XYZSequenceTag& sequence = component.measurement().line().xyzSequence(sindex);
    object->setCoords( sequence.xyz() );
    object->setColor( kvs::RGBColor::Black() );
    object->setSize(1);
    object->setLineTypeToStrip();

    object->updateMinMaxCoords();
    const float xscale = bdml.data().scaleUnit().xScale();
    const float yscale = bdml.data().scaleUnit().yScale();
    const float zscale = bdml.data().scaleUnit().zScale();
    const kvs::Vec3 scale( xscale, yscale, zscale );
    const kvs::Vec3 min_coord = object->minExternalCoord() * scale;
    const kvs::Vec3 max_coord = object->maxExternalCoord() * scale;
    object->setMinMaxExternalCoords( min_coord, max_coord );

    return object;
}

kvs::LineObject* ImportLineObjectByComponent( const ReadBDML::BDMLData& bdml, const size_t cindex )
{
    kvs::LineObject* object = new kvs::LineObject();

    kvs::ValueArray<kvs::Real32> coords;
    std::vector<kvs::UInt32> connections;

    const ReadBDML::bdml::ComponentTag& component = bdml.data().component(cindex);
    const size_t nsequences = component.measurement().line().xyzSequences().size();
    for ( size_t sindex = 0; sindex < nsequences; sindex++ )
    {
        connections.push_back( coords.size() / 3 );

        const ReadBDML::bdml::XYZSequenceTag& sequence = component.measurement().line().xyzSequence(sindex);
        kvs::ValueArray<float> temp( coords.size() + sequence.xyz().size() );
        memcpy( temp.data(), coords.data(), coords.byteSize() );
        memcpy( temp.data() + coords.size(), sequence.xyz().data(), sequence.xyz().byteSize() );
        coords = temp;

        connections.push_back( coords.size() / 3 - 1 );
    }

    object->setCoords( coords );
    object->setConnections( kvs::ValueArray<kvs::UInt32>( connections ) );
    object->setColor( kvs::RGBColor::Black() );
    object->setSize(1);
    object->setLineTypeToPolyline();

    object->updateMinMaxCoords();
    const float xscale = bdml.data().scaleUnit().xScale();
    const float yscale = bdml.data().scaleUnit().yScale();
    const float zscale = bdml.data().scaleUnit().zScale();
    const kvs::Vec3 scale( xscale, yscale, zscale );
    const kvs::Vec3 min_coord = object->minExternalCoord() * scale;
    const kvs::Vec3 max_coord = object->maxExternalCoord() * scale;
    object->setMinMaxExternalCoords( min_coord, max_coord );

    return object;
}

kvs::LineObject* ImportLineObjectByTime( const ReadBDML::BDMLData& bdml, const float time )
{
    kvs::LineObject* object = new kvs::LineObject();

    kvs::ValueArray<kvs::Real32> coords;
    std::vector<kvs::UInt32> connections;

    const size_t ncomponents = bdml.data().components().size();
    for ( size_t cindex = 0; cindex < ncomponents; cindex++ )
    {
        const ReadBDML::bdml::ComponentTag& component = bdml.data().component(cindex);
        if ( component.time() == time )
        {
            const size_t nsequences = component.measurement().line().xyzSequences().size();
            for ( size_t sindex = 0; sindex < nsequences; sindex++ )
            {
                connections.push_back( coords.size() / 3 );

                const ReadBDML::bdml::XYZSequenceTag& sequence = component.measurement().line().xyzSequence(sindex);
                kvs::ValueArray<float> temp( coords.size() + sequence.xyz().size() );
                memcpy( temp.data(), coords.data(), coords.byteSize() );
                memcpy( temp.data() + coords.size(), sequence.xyz().data(), sequence.xyz().byteSize() );
                coords = temp;

                connections.push_back( coords.size() / 3 - 1 );
            }
        }
    }

    object->setCoords( coords );
    object->setConnections( kvs::ValueArray<kvs::UInt32>( connections ) );
    object->setColor( kvs::RGBColor::Black() );
    object->setSize(1);
    object->setLineTypeToPolyline();

    object->updateMinMaxCoords();
    const float xscale = bdml.data().scaleUnit().xScale();
    const float yscale = bdml.data().scaleUnit().yScale();
    const float zscale = bdml.data().scaleUnit().zScale();
    const kvs::Vec3 scale( xscale, yscale, zscale );
    const kvs::Vec3 min_coord = object->minExternalCoord() * scale;
    const kvs::Vec3 max_coord = object->maxExternalCoord() * scale;
    object->setMinMaxExternalCoords( min_coord, max_coord );

    return object;
}

} // end of namespace ReadBDML
