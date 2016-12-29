#include <ReadBDML/Lib/BDMLData.h>


int main( int argc, char** argv )
{
    ReadBDML::BDMLData bdml( argv[1] );

    std::cout << "Feature Name: " << bdml.data().feature().featureName() << std::endl;
    std::cout << "Feature Scale: " << bdml.data().feature().featureScale() << std::endl;
    std::cout << "Feature Unit: " << bdml.data().feature().featureUnit() << std::endl;
    std::cout << std::endl;
    std::cout << "Number of Components: " << bdml.data().components().size() << std::endl;
    for ( size_t i = 0; i < bdml.data().components().size(); i++ )
    {
        std::cout << "    Component[" << i << "]:" << std::endl;
        std::cout << "        Feature Ref.: " << bdml.data().component(i).measurement().property().featureRef() << std::endl;
        std::cout << "        Feature Val.: " << bdml.data().component(i).measurement().property().featureVal() << std::endl;
    }

    return 0;
}
