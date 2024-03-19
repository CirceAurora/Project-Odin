class MOD_CLASS {
    class Config {
        ODIN_CONFIG(zeus);
    };

    class Functions {
        ODIN_FUNCTION_SERVER(setupZeus,-200);
        ODIN_FUNCTION_SERVER(createZeusModules,-100);
        ODIN_FUNCTION_SERVER(deleteZeusModules,100);
        ODIN_FUNCTION_SERVER(updateEditableObjects,100);
        ODIN_FUNCTION_SERVER(zeusLogging,0);
        ODIN_FUNCTION_SERVER(shareCreated,0);
    };
};
