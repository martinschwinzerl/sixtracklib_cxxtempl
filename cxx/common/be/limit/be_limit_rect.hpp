#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/be/limit/be_limit_rect_data.hpp"
#include "cxx/common/be/limit/be_limit_rect.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeLimitRectBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef typename BeLimitRectTraits< BeObjData >::real_t  real_t;
        typedef ::NS(BeLimitRect)                                c_api_t;

        SIXTRL_FN BeLimitRectBase() = default;

        SIXTRL_FN BeLimitRectBase(
            BeLimitRectBase< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitRectBase(
            BeLimitRectBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeLimitRectBase< BeObjData >& operator=(
            BeLimitRectBase< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitRectBase< BeObjData >& operator=(
            BeLimitRectBase< BeObjData >&& other ) = default;

        SIXTRL_FN virtual ~BeLimitRectBase() = default;

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

    typedef BeLimitRectBase< ::NS(BeLimitRect) >            CBeLimitRect;
    typedef BeLimitRectBase< BeLimitRectData< double > >    BeLimitRect;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeLimitRect = BeLimitRectBase< BeLimitRectData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_CXX_HPP__ */
/* end: */
