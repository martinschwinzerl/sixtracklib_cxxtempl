#ifndef SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/multipole/be_multipole_traits.hpp"
#include "cxx/common/be/multipole/be_multipole_data.hpp"
#include "cxx/common/be/multipole/be_multipole.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeMultipoleBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef typename BeMultipoleTraits< BeObjData >::real_t  real_t;
        typedef typename BeMultipoleTraits< BeObjData >::order_t order_t;

        SIXTRL_FN BeMultipoleBase() = default;

        SIXTRL_FN BeMultipoleBase(
            BeMultipoleBase< BeObjData > const& other) = default;

        SIXTRL_FN BeMultipoleBase(
            BeMultipoleBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeMultipoleBase< BeObjData >& operator=(
            BeMultipoleBase< BeObjData > const& other) = default;

        SIXTRL_FN BeMultipoleBase< BeObjData >& operator=(
            BeMultipoleBase< BeObjData >&& other ) = default;

        SIXTRL_FN virtual ~BeMultipoleBase() = default;

        real_t const& operator[]( order_t const index ) const SIXTRL_NOEXCEPT
        {
            return sixtrack_cxx::BeMultipoleData_get_const_bal( *this, index );
        }

        real_t& operator[]( order_t const index ) SIXTRL_NOEXCEPT
        {
            return sixtrack_cxx::BeMultipoleData_get_bal( *this, index );
        }

        real_t const& getBal( order_t const index ) const SIXTRL_NOEXCEPT
        {
            return sixtrack_cxx::BeMultipoleData_get_const_bal( *this, index );
        }

        real_t& getBal( order_t const index ) SIXTRL_NOEXCEPT
        {
            return sixtrack_cxx::BeMultipoleData_get_bal( *this, index );
        }

        /* TODO: Add missing calculation of inverse factorial factors ->
         * this is an interesting test for the generic type! */

        /*
        real_t const& knl( order_t const index ) const SIXTRL_NOEXCEPT
        {
            namespace stcxx = sixtrack_cxx;
            order_t const knl_index = static_cast< order_t >( 2u ) * index;
            return stcxx::BeMultipoleData_get_const_bal( *this, knl_index );
        }

        real_t const& ksl( order_t const index ) const SIXTRL_NOEXCEPT
        {
            namespace stcxx = sixtrack_cxx;
            order_t const ksl_index = static_cast< order_t >( 2u ) * index +
                static_cast< order_t >( 1u );
            return stcxx::BeMultipoleData_get_const_bal( *this, ksl_index );
        }

        real_t& knl( order_t const index ) SIXTRL_NOEXCEPT
        {
            order_t const knl_index = static_cast< order_t >( 2u ) * index;
            return sixtrack_cxx::BeMultipoleData_get_bal( *this, knl_index );
        }

        real_t& ksl( order_t const index ) SIXTRL_NOEXCEPT
        {
            order_t const ksl_index = static_cast< order_t >( 2u ) * index +
                static_cast< order_t >( 1u );
            return sixtrack_cxx::BeMultipoleData_get_bal( *this, ksl_index );
        }
        */

        order_t getOrder() const SIXTRL_NOEXCEPT
        {
            return sixtrack_cxx::BeMultipoleData_get_order( *this );
        }

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

    typedef BeMultipoleBase< ::NS(BeMultipole) >            CBeMultipole;
    typedef BeMultipoleBase< BeMultipoleData< double > >    BeMultipole;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign(),
        std::size_t OAlign = sixtrack_cxx::TypeStoreTraits<
            ::NS(be_multipole_order_t) >::StorageAlign() >
    using TBeMultipole = BeMultipoleBase< BeMultipoleData< R, RAlign, OAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_CXX_HPP__ */
/* end: */
