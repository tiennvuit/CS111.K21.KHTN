        clear flag;        # init flag = 0
        incr flag;

        clear Z;
        Z <- X;

        while flag not 0 do
                clear flag;
                X1 <- Z
                Y1 <- Y

                # Check X1 < Y1 ?
                while Y1 not 0 do
                    incr flag;
                    decr Y1;
                end;
                while X1 not 0 do
                    decr flag;
                    decr X1;
                end;
                if kq not 0 then
                        flag:= 0
                else flag:= 1

                invert flag;

                if flag not 0 do

                    # Z = Z - Y
                    clear temp;
                    while Y not 0 do
                        decr Z;
                        incr temp;
                    end;
                    while temp not 0 do
                        incr Y
                        decr temp;
                    end;
        end;
