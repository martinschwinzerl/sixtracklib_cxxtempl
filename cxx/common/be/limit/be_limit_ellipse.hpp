#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/be/limit/be_limit_ellipse_data.hpp"
#include "cxx/common/be/limit/be_limit_ellipse.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeLimitEllipseBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef typename BeLimitEllipseTraits< BeObjData >::real_t  real_t;
        typedef ::NS(BeLimitEllipse)                                c_api_t;

        SIXTRL_FN BeLimitEllipseBase() = default;

        SIXTRL_FN BeLimitEllipseBase(
            BeLimitEllipseBase< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitEllipseBase(
            BeLimitEllipseBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeLimitEllipseBase< BeObjData >& operator=(
            BeLimitEllipseBase< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitEllipseBase< BeObjData >& operator=(
            BeLimitEllipseBase< BeObjData >&& other ) = default;

        SIXTRL_FN virtual ~BeLimitEllipseBase() = default;

        protected:

        SIXTRL_FN be_data_t* ptrBeData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t* >( this );
        }

        SIXTRL_FN be_data_t const* ptrBeData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const* >( this );
        }

        SIXTRL_FN be_data_t& beData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t& >( *this );
        }

        SIXTRL_FN be_data_t const& beData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const& >( *this );
        }
    };

    /* --------------------------------------------------------------------- */

    typedef BeLimitEllipseBase< ::NS(BeLimitEllipse) >          CBeLimitEllipse;
    typedef BeLimitEllipseBase< BeLimitEllipseData< double > >  BeLimitEllipse;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeLimitEllipse = BeLimitEllipseBase< BeLimitEllipseData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_CXX_HPP__ */
/* end: */
