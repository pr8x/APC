Import("env")

env.Append(LINKFLAGS=[ "--specs=nano.specs", "-u_printf_float", "-u_scanf_float" ] )