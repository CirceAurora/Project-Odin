class MOD_CLASS {
    class Config {
        ODIN_CONFIG(channels);
    };

    class Functions {
        ODIN_FUNCTION_SERVER(createChannels,-100);
        ODIN_FUNCTION_INTERFACE(addChannels,100);
        ODIN_FUNCTION_INTERFACE(readdChannels,100);
    };
};
