#ifndef SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/cavity/be_cavity_traits.hpp"
#include "cxx/common/be/cavity/be_cavity_data.hpp"
#include "cxx/common/be/cavity/be_cavity.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeCavityBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef typename BeCavityTraits< BeObjData >::real_t  real_t;
        typedef typename BeCavityTraits< BeObjData >::order_t order_t;

        SIXTRL_FN BeCavityBase() = default;

        SIXTRL_FN BeCavityBase(
            BeCavityBase< BeObjData > const& other) = default;

        SIXTRL_FN BeCavityBase(
            BeCavityBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeCavityBase< BeObjData >& operator=(
            BeCavityBase< BeObjData > const& other) = default;

        SIXTRL_FN BeCavityBase< BeObjData >& operator=(
            BeCavityBase< BeObjData >&& other ) = default;

        SIXTRL_FN virtual ~BeCavityBase() = default;

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

    typedef BeCavityBase< ::NS(BeCavity) >            CBeCavity;
    typedef BeCavityBase< BeCavityData< double > >    BeCavity;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeCavity = BeCavityBase< BeCavityData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__ */
/* end: */
