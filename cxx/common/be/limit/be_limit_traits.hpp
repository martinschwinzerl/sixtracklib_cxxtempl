#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_BE_LIMIT_TRAITS_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_LIMIT_BE_LIMIT_TRAITS_CXX_HPP__

namespace sixtrack_cxx
{
    template< class BeObjData >
    struct BeLimitRectTraits
    {
        typedef typename BeObjData::real_t real_t;
    };

    template< class BeObjData >
    struct BeLimitEllipseTraits
    {
        typedef typename BeObjData::real_t real_t;
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_BE_LIMIT_TRAITS_CXX_HPP__ */
/* end: */
