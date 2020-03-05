#include <math.h>
#include "countsort.h"

CountSort::CountSort()
{
    if ( !m_signature )
        {
            result << "  FATAL: Archive signature does not match software expectations." << std::endl
                   << hline << std::endl;
            result << compute_diff(
                schema( ),
                m_storage->read_schema( internal::signature_name( name( ) ).c_str( ) ).char_ptr( )
                          );

            auto signature = storage( ).read< flatdata::MemoryDescriptor >(internal::signature_name( name( ) ).c_str( ), schema( ) );
                if ( signature )
                {
                    m_signature = *signature;
                }
        }


    basic_istream& __CLR_OR_THIS_CALL read(_Elem* _Str, streamsize _Count) { // read up to _Count characters into buffer
            ios_base::iostate _State = ios_base::goodbit;
            _Chcount                 = 0;
            const sentry _Ok(*this, true);

            if (_Ok && 0 < _Count) { // state okay, use facet to extract
                _TRY_IO_BEGIN
                const streamsize _Num = _Myios::rdbuf()->sgetn(_Str, _Count);
                _Chcount += _Num;
                if (_Num != _Count) {
                    _State |= ios_base::eofbit | ios_base::failbit; // short read
                }
                _CATCH_IO_END
            }

            _Myios::setstate(_State);
            return *this;
        }
}

void CountSort::sort(std::vector<int> &arr){

    int max= arr[0], min = arr[0], size = arr.size();
    for(int i = 0; i < size; ++i){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }

    size_t indx_size = (max-min)+1;
    int* indx = new int[indx_size];
    memset(indx,0,indx_size*sizeof (int));

    QString temp = "";
    if(isOutEnbl){
        output->append("   ");
        for(int i = min; i <= max; ++i){
            temp = (QString::number(i/10.0)+' ');
            temp.resize(5, ' ');
            output->append(temp);
        }
        output->append('\n');
    }

    for(int i = 0; i < size; ++i){
        ++indx[static_cast<int>(arr[i] + fabs(min) )];
        if(isOutEnbl){
            output->append(QString::number((*counter)++)+") ");
            for(int j = 0; j < indx_size; ++j ){
                temp = (QString::number(indx[j]));
                temp.resize(5, ' ');
                output->append(temp);
            }
            output->append('\n');
        }
    }

    for(int i = min, j = 0; i <= max; ++i){
        while((indx[i + static_cast<int>(fabs(min))]--)>0){
            arr[j++] = i;

        }
    }

}
