#ifndef SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_CXX_HPP__

#include "sixtracklib/common/definitions.h"

#include "cxx/common/be/xyshift/be_xyshift_traits.hpp"
#include "cxx/common/be/xyshift/be_xyshift_data.hpp"
#include "cxx/common/be/xyshift/be_xyshift.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeXYShiftBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef typename BeXYShiftTraits< BeObjData >::real_t  real_t;
        typedef ::NS(BeXYShift)                                c_api_t;

        SIXTRL_FN BeXYShiftBase() = default;

        SIXTRL_FN BeXYShiftBase(
            BeXYShiftBase< BeObjData > const& other) = default;

        SIXTRL_FN BeXYShiftBase(
            BeXYShiftBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeXYShiftBase< BeObjData >& operator=(
            BeXYShiftBase< BeObjData > const& other) = default;

        SIXTRL_FN BeXYShiftBase< BeObjData >& operator=(
            BeXYShiftBase< BeObjData >&& other ) = default;

        SIXTRL_FN virtual ~BeXYShiftBase() = default;

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

    typedef BeXYShiftBase< ::NS(BeXYShift) >            CBeXYShift;
    typedef BeXYShiftBase< BeXYShiftData< double > >    BeXYShift;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeXYShift = BeXYShiftBase< BeXYShiftData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_CXX_HPP__ */
/* end: */
