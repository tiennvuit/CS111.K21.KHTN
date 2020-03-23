        # Initialize Y = X
        clear Y;
        clear temp;
        while X not 0 do
            incr Y;
            incr temp;
            decr X;
        end;
        while temp not 0 do
            incr X;
            decr temp;
        end;

        # Initialize Z = 0, Z will be result.
        clear Z;
        while Y not 0 do
            clear temp;
            while Y not 0 do
                incr temp;
                incr Z;
                decr Y;
            end;

            while temp not 0 do
                incr Y;
                decr temp;
            end;
            decr Y;
        end;
