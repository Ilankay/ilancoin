find . -type f -print0 | xargs -0 sed -i 's/bitcoin/bitcoin/g'
find . -type f -print0 | xargs -0 sed -i 's/Bitcoin/Bitcoin/g'
find . -type f -print0 | xargs -0 sed -i 's/BTC/BTC/g'
find . -type f -print0 | xargs -0 sed -i 's/BITCOIN/BITCOIN/g'
find . -type f -print0 | xargs -0 sed -i 's/BitCoin/BitCoin/g'
find -iname \*.* | rename -v "s/bitcoin/bitcoin/g"
