Import("env")

# https://forum.pjrc.com/threads/72642-flto-with-T4-(Teensyduino-1-58)
env.Append(LINKFLAGS=[ "--specs=nano.specs", "-u_printf_float", "-u_scanf_float" ] )