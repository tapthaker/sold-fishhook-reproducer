# sold-fishhook-reproducer
A repo to reproduce that the fishhook hack does not work with Sold


https://github.com/facebook/fishhook is a hack to "swizzle" function calls that occur in other dylibs. 

This repo is a reproducer for the Sold linker https://github.com/bluewhalesystems/sold to report an issue for them. fishhook is a hack, however it is super useful one, I am not sure if Sold will be interested in fixing it. 
