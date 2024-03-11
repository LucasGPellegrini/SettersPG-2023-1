import os
import sys

testset = []
with open('inputs', 'r') as f:
    s = ''
    while True:
        line = f.readline()
        if not line:
            break
        if line not in ['\n', '\r\n']:
            s += line
        else:
            testset.append(s[:-1])  # sem o ultimo \n
            s = ''


if len(sys.argv) < 3:
    os.system('echo "missing arguments, nothing done"')
elif len(sys.argv) > 3:
    os.system('echo "surplussing arguments, nothing done"')
else:
    source_code = 'solucoes/' + sys.argv[2]
    os.system('g++ -o bin ' + source_code)
    os.system('echo "code compiled!"')

    for idx, inpt in enumerate(testset):
        in_fname = sys.argv[1] + '/input/' + str(idx+1).zfill(3)
        with open(in_fname, 'w') as f:
            f.write(inpt)

        out_fname = sys.argv[1] + '/output/' + str(idx+1).zfill(3)
        os.system('./bin < ' + in_fname + ' >> ' + out_fname)

    os.system('rm bin')
    os.system('echo "all done, cleaning binaries"')
