
// Copyright (c) 2018 Eric Parent
// Copyright (c) 2018 The Crow Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

void main() {

  CBlock genesis;
  
  genesis = CreateGenesisBlock(1530974244, 0, 0x1e00ffff, 4, 5000 * COIN);

  if (true && genesis.GetHash() != hashGenesisBlock) {
    
    printf("recalculating params for mainnet.\n");
    printf("old mainnet genesis nonce: %s\n", genesis.nNonce.ToString().c_str());
    printf("old mainnet genesis hash:  %s\n", hashGenesisBlock.ToString().c_str());
  
    for(genesis.nNonce == 0; genesis.GetHash() > bnProofOfWorkLimit; genesis.nNonce++){ }
  
    printf("new mainnet genesis merkle root: %s\n", genesis.hashMerkleRoot.ToString().c_str());
    printf("new mainnet genesis nonce: %s\n", genesis.nNonce.ToString().c_str());
    printf("new mainnet genesis hash: %s\n", genesis.GetHash().ToString().c_str());
    
  }

}


