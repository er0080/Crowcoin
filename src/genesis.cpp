
// Copyright (c) 2018 Eric Parent
// Copyright (c) 2018 The Crow Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.cpp"
#include <sstream>
#include "pow.h"
#include <consensus/consensus.h>
#include <consensus/params.h>
#include <consensus/validation.h>

int main(int argc, char* argv[]) {

  uint32_t nBits = 0x1e00ffff;
  CBlock genesis = CreateGenesisBlock(1530974244, 0, nBits, 4, 5000 * COIN);
  
  Consensus::Params consensus;
  consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); 

  printf("Hashing genesis block: CreateGenesisBlock(1530974244, nonce, %#010x, 4, 5000 * COIN)\n", nBits);
  
  while (!CheckProofOfWork(genesis.GetHash(), nBits, consensus))
  {
    genesis.nNonce++;
  }
  
  printf("Genesis merkle root: %s\n", genesis.hashMerkleRoot.ToString().c_str());
  printf("Genesis nonce: %u\n", genesis.nNonce);
  printf("Genesis hash: %s\n", genesis.GetHash().ToString().c_str());
    
  return 0;
    

}


