        # Init the value Y = X
        clear Y;
        clear temp;
        while X not 0 do
            incr Y;
            incr temp;
            decr X;
        end;
        # restore value to X
        while temp not 0 do
            incr X;
            decr temp;
        end;

        clear Z;        # initialize Z = 0

        while Y not 0 do
            clear W;      # initialize W = 0 and W will store current value X
            while X not 0 do
                incr Z;
                incr W;
                decr X;
            end;

            # Restore value to X
            while W not 0:
                incr X;
                decr W;
            end;
            
            decr Y;
        end;
