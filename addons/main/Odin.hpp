class MOD_CLASS {
    class Config {
        ODIN_CONFIG(logging);
        ODIN_CONFIG(staff);
    };

    class Functions {
       ODIN_FUNCTION_ALL(log,0);
       ODIN_FUNCTION_SERVER(loadConfig,-1000);

       ODIN_FUNCTION_SERVER(message,0);
       ODIN_FUNCTION_INTERFACE(messageInit,-100);
       ODIN_FUNCTION_INTERFACE(receiveMessage,0);
    };
};
