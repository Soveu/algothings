#include<stdint.h>
#include<stddef.h>

#include<array>
#include<iostream>
#include<cassert>

using StanGry = std::array<uint32_t, 3>;

/*
 * każdy stan nieparzysty można doprowadzić do stanu parzystego
 * każdy stan parzysty doprowadza do nieparzystego
 * stan końcowy == parzysty
 */

constexpr bool czyParzysta(const StanGry& s) noexcept{
  for(size_t i=0; i < 8*sizeof(StanGry::value_type); ++i){
    if( (s[0] >> i) + (s[1] >> i) + (s[2] >> i) & 1 == 1 )
      return false;
  }

  return true;
}

int main(){
  static_assert(czyParzysta({0,0,0}) == true);
  static_assert(czyParzysta({3,1,2}) == true);
  static_assert(czyParzysta({0,0,1}) == true);

  return 0;
}
