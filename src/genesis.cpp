
// Copyright (c) 2018 Eric Parent
// Copyright (c) 2018 The Crow Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.cpp"
#include <sstream>

int main(int argc, char* argv[]) {

  uint32_t nBits = 0x1e00ffff;
/*  int i;

  for (i=0; i < argc; i++){
    printf("%s\n", argv[i]); 
  }

  if (argc > 0) {  
    std::istringstream ss( argv[0] );
    
    if (ss >> diff) {
      printf("Invalid difficulty.\n");
      return 1;
    }
  }
*/
  CBlock genesis = CreateGenesisBlock(1530974244, 0, nBits, 4, 5000 * COIN);

  printf("Hashing genesis block: CreateGenesisBlock(1530974244, nonce, %#010x, 4, 5000 * COIN)\n", nBits);

  for(genesis.nNonce = 0; genesis.GetHash() < uint256S("0x000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); genesis.nNonce++)
  {
  }
  
  printf("Genesis merkle root: %s\n", genesis.hashMerkleRoot.ToString().c_str());
  printf("Genesis nonce: %u\n", genesis.nNonce);
  printf("Genesis hash: %s\n", genesis.GetHash().ToString().c_str());
    
  return 0;
    

}


