// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Elephancoin Developers
// Copyright (c) 2014 ColaCoin Developer - CCP
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
(0,      uint256("0xb11eef43e4f5c64dfd1f7956e39641aa5d512e9aeb242b7f51b4c531085279db"))
(555,    uint256("0xfb440fd8fba7be36d0f8b9240506c75ee76b22f299ffa422fb7e6e5f0e618a3a"))
(21572,  uint256("0x749cf9a2c247991c5a7348b4deeee9f9ce3c5aaa45e978917520eab6d7831794"))
(43849,  uint256("0xbf50a574c86b8ed7922d8e74af396e111482ce5e6851625e612e8f3755c010a9"))
(83561,  uint256("0xc11a6224c2270709ecf0cb6d364a3e1047e2cbc89a1a3a778f7e6f689782be10"))
(127451, uint256("0x5c776dfac38f024a9bd9a37d22703e3b9ebb1920036ae6670c95e762ddb67552"))
(172718, uint256("0x73b09f7c4c76687717e74c507f5822aeaa0d47b22dbdc7dcb90d1474c491ffaa"))
(235735, uint256("0xae9f6952f2ca4eb99ee398abb5d41d66b57355a4ddd60d199550cdf65dbd9e58"))
(267345, uint256("0xe5909049f45a57b687685061bd8412a4cb7c9292e7aab61a7ce6c583fc2238ee"))
(295635, uint256("0x5845a120af84fd7376a5a917ef059f8dcead3c730cddb5b80291af1396645a3c"))
(325650, uint256("0x0ec2c24835f8a3b5a2c7e0eb6299c99b239bb3413ac8b30a475580ade8973a9b"))
(358373, uint256("0x1185a777c46cb3f6fb6079544617c5be2809b57659097fa30d8da5fd4d3908bd"))
(367258, uint256("0x4fa9ea3cf7d14e96e737ecaac55374e257a154f4895f75a7c0610d062a5f2cd4"))
;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;

//### Default Value
return hash == i->second;

//### Produce Value
//return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

//### Default Value
return mapCheckpoints.rbegin()->first;

//### Produce Value
//return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
//### Default Value
return t->second;

//### Produce Value
//return NULL;
        }
        return NULL;
    }
}
