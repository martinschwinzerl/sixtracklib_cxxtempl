#ifndef SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/srotation/be_srotation_traits.hpp"
#include "cxx/common/be/srotation/be_srotation_data.hpp"
#include "cxx/common/be/srotation/be_srotation.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeSRotationBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef typename BeSRotationTraits< BeObjData >::real_t  real_t;
        typedef ::NS(BeSRotation)                                c_api_t;

        SIXTRL_FN BeSRotationBase() = default;

        SIXTRL_FN BeSRotationBase(
            BeSRotationBase< BeObjData > const& other) = default;

        SIXTRL_FN BeSRotationBase(
            BeSRotationBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeSRotationBase< BeObjData >& operator=(
            BeSRotationBase< BeObjData > const& other) = default;

        SIXTRL_FN BeSRotationBase< BeObjData >& operator=(
            BeSRotationBase< BeObjData >&& other ) = default;

        SIXTRL_FN virtual ~BeSRotationBase() = default;

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

    typedef BeSRotationBase< ::NS(BeSRotation) >            CBeSRotation;
    typedef BeSRotationBase< BeSRotationData< double > >    BeSRotation;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeSRotation = BeSRotationBase< BeSRotationData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_CXX_HPP__ */
/* end: */
