import subprocess
import time

def run(exe, inputfunc, timeout=1, tests=10):
    averagetime = 0

    for i in range(1, tests+1):
        give, expect = inputfunc(i)
        print("[%02d/%02d] " % (i, tests), end='', flush=True)
        timep = time.perf_counter()

        try:
            proc = subprocess.run(
                    [exe], 
                    capture_output=True, 
                    input=give, 
                    check=True,
                    timeout=timeout
                )
        except subprocess.TimeoutExpired as e:
            print('FAIL')
            print("Timed out after %.02f seconds" % e.timeout)
            return
        except subprocess.CalledProcessError as e:
            print('FAIL')
            print("Process '%s' returned non-zero exit status %d" % (e.cmd, e.returncode))
            print(e.stdout.decode('utf-8'))
            print(e.stderr.decode('utf-8'))
            return

        deltatime = time.perf_counter() - timep
        averagetime += (deltatime - averagetime) / i
    
        if(expect == proc.stdout):
            print("Time: %fs, Average: %fs" % (deltatime, averagetime))
        else:
            print('FAIL')
            print("Expected:", expect)
            print("Got:", proc.stdout)
            return

