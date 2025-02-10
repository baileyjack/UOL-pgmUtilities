clear

echo The tests on the PGM Utilities programs will now run. To stop running this script, press CTRL + C at any time.

sleep 3

make clean
echo Cleaned Up from previous tests.

sleep 3

echo Compiling...
make all
echo Done.

sleep 3

echo Test Set 1: Correct Messages with No Arguments Supplied
if ./pgmEcho | grep -q "Usage: ./pgmEcho inputImage.pgm outputImage.pgm";
then
    echo 'pgmEcho - Correct No Argument Error - PASSED' >> tests.out
else
    echo 'pgmEcho - Correct No Argument Error - FAILED' >> tests.out
fi

if ./pgmComp | grep -q "Usage: ./pgmComp inputImage.pgm inputImage.pgm";
then
    echo 'pgmComp - Correct No Argument Error - PASSED' >> tests.out
else
    echo 'pgmComp - Correct No Argument Error - FAILED' >> tests.out
fi

if ./pgma2b | grep -q "Usage: ./pgma2b inputImage.pgm outputImage.pgm";
then
    echo 'pgma2b - Correct No Argument Error - PASSED' >> tests.out
else
    echo 'pgma2b - Correct No Argument Error - FAILED' >> tests.out
fi

if ./pgmb2a | grep -q "Usage: ./pgmb2a inputImage.pgm outputImage.pgm";
then
    echo 'pgmb2a - Correct No Argument Error - PASSED' >> tests.out
else
    echo 'pgmb2a - Correct No Argument Error - FAILED' >> tests.out
fi

if ./pgmReduce | grep -q "Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm";
then
    echo 'pgmReduce - Correct No Argument Error - PASSED' >> tests.out
else
    echo 'pgmReduce - Correct No Argument Error - FAILED' >> tests.out
fi

echo >> tests.out
echo Test Set 2: pgmEcho Errors
if ./pgmEcho ASCI.pgm | grep -q "ERROR: Bad Argument Count";
then
    echo 'pgmEcho - Correct Bad Argument Count - PASSED' >> tests.out
else
    echo 'pgmEcho - Correct Bad Argument Count - FAILED' >> tests.out
fi

if ./pgmEcho ASCI.pgm ASCIIEchoed.pgm | grep -q "ERROR: Bad File Name (ASCI.pgm)";
then
    echo 'pgmEcho - Correct Error Bad File Name - PASSED' >> tests.out
else
    echo 'pgmEcho - Correct Error Bad File Name - FAILED' >> tests.out
fi

if ./pgmEcho ASCIITestFiles/ASCIIBadComment.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Comment Line (ASCIITestFiles/ASCIIBadComment.pgm)";
then
    echo 'pgmEcho - Correct Error Bad Comment Line - PASSED' >> tests.out
else
    echo 'pgmEcho - Correct Error Bad Comment Line - FAILED' >> tests.out
fi

if ./pgmEcho ASCIITestFiles/ASCIIBadDimension.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Dimensions (ASCIITestFiles/ASCIIBadDimension.pgm)";
then
    echo 'pgmEcho - Correct Error Bad Dimensions - PASSED' >> tests.out
else
    echo 'pgmEcho - Correct Error Bad Dimensions - FAILED' >> tests.out
fi

if ./pgmEcho ASCIITestFiles/ASCIIBadMagicNumber.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Magic Number (ASCIITestFiles/ASCIIBadMagicNumber.pgm)";
then
    echo 'pgmEcho - Correct Error Bad Magic Number - PASSED' >> tests.out
else
    echo 'pgmEcho - Correct Error Bad Magic Number - FAILED' >> tests.out
fi

if ./pgmEcho ASCIITestFiles/ASCIITooLittleData.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Data (ASCIITestFiles/ASCIITooLittleData.pgm)";
then
    echo 'pgmEcho - Correct Error Bad Data (Too Little) - PASSED' >> tests.out
else
    echo 'pgmEcho - Correct Error Bad Data (Too Little) - FAILED' >> tests.out
fi

if ./pgmEcho ASCIITestFiles/ASCIITooMuchData.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Data (ASCIITestFiles/ASCIITooMuchData.pgm)";
then
    echo 'pgmEcho - Correct Error Bad Data (Too Much) - PASSED' >> tests.out
else
    echo 'pgmEcho - Correct Error Bad Data (Too Much) - FAILED' >> tests.out
fi


echo >> out
echo Test Set 3: pgmComp Errors
if ./pgmComp ASCI.pgm | grep -q "ERROR: Bad Argument Count";
then
    echo 'pgmComp - Correct Bad Argument Count - PASSED' >> tests.out
else
    echo 'pgmComp - Correct Bad Argument Count - FAILED' >> tests.out
fi

if ./pgmComp ASCI.pgm ASCIIEchoed.pgm | grep -q "ERROR: Bad File Name (ASCI.pgm)";
then
    echo 'pgmComp - Correct Error Bad File Name - PASSED' >> tests.out
else
    echo 'pgmComp - Correct Error Bad File Name - FAILED' >> tests.out
fi

if ./pgmComp ASCIITestFiles/ASCIIBadComment.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Comment Line (ASCIITestFiles/ASCIIBadComment.pgm)";
then
    echo 'pgmComp - Correct Error Bad Comment Line - PASSED' >> tests.out
else
    echo 'pgmComp - Correct Error Bad Comment Line - FAILED' >> tests.out
fi

if ./pgmComp ASCIITestFiles/ASCIIBadDimension.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Dimensions (ASCIITestFiles/ASCIIBadDimension.pgm)";
then
    echo 'pgmComp - Correct Error Bad Dimensions - PASSED' >> tests.out
else
    echo 'pgmComp - Correct Error Bad Dimensions - FAILED' >> tests.out
fi

if ./pgmComp ASCIITestFiles/ASCIIBadMagicNumber.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Magic Number (ASCIITestFiles/ASCIIBadMagicNumber.pgm)";
then
    echo 'pgmComp - Correct Error Bad Magic Number - PASSED' >> tests.out
else
    echo 'pgmComp - Correct Error Bad Magic Number - FAILED' >> tests.out
fi

if ./pgmComp ASCIITestFiles/ASCIITooLittleData.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Data (ASCIITestFiles/ASCIITooLittleData.pgm)";
then
    echo 'pgmComp - Correct Error Bad Data (Too Little) - PASSED' >> tests.out
else
    echo 'pgmComp - Correct Error Bad Data (Too Little) - FAILED' >> tests.out
fi

if ./pgmComp ASCIITestFiles/ASCIITooMuchData.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Data (ASCIITestFiles/ASCIITooMuchData.pgm)";
then
    echo 'pgmComp - Correct Error Bad Data (Too Much) - PASSED' >> tests.out
else
    echo 'pgmComp - Correct Error Bad Data (Too Much) - FAILED' >> tests.out
fi


echo >> out
echo Test Set 4: pgma2b Errors
if ./pgma2b ASCI.pgm | grep -q "ERROR: Bad Argument Count";
then
    echo 'pgma2b - Correct Bad Argument Count - PASSED' >> tests.out
else
    echo 'pgma2b - Correct Bad Argument Count - FAILED' >> tests.out
fi

if ./pgma2b ASCI.pgm ASCIIEchoed.pgm | grep -q "ERROR: Bad File Name (ASCI.pgm)";
then
    echo 'pgma2b - Correct Error Bad File Name - PASSED' >> tests.out
else
    echo 'pgma2b - Correct Error Bad File Name - FAILED' >> tests.out
fi

if ./pgma2b ASCIITestFiles/ASCIIBadComment.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Comment Line (ASCIITestFiles/ASCIIBadComment.pgm)";
then
    echo 'pgma2b - Correct Error Bad Comment Line - PASSED' >> tests.out
else
    echo 'pgma2b - Correct Error Bad Comment Line - FAILED' >> tests.out
fi

if ./pgma2b ASCIITestFiles/ASCIIBadDimension.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Dimensions (ASCIITestFiles/ASCIIBadDimension.pgm)";
then
    echo 'pgma2b - Correct Error Bad Dimensions - PASSED' >> tests.out
else
    echo 'pgma2b - Correct Error Bad Dimensions - FAILED' >> tests.out
fi

if ./pgma2b ASCIITestFiles/ASCIIBadMagicNumber.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Magic Number (ASCIITestFiles/ASCIIBadMagicNumber.pgm)";
then
    echo 'pgma2b - Correct Error Bad Magic Number - PASSED' >> tests.out
else
    echo 'pgma2b - Correct Error Bad Magic Number - FAILED' >> tests.out
fi

if ./pgma2b ASCIITestFiles/ASCIITooLittleData.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Data (ASCIITestFiles/ASCIITooLittleData.pgm)";
then
    echo 'pgma2b - Correct Error Bad Data (Too Little) - PASSED' >> tests.out
else
    echo 'pgma2b - Correct Error Bad Data (Too Little) - FAILED' >> tests.out
fi

if ./pgma2b ASCIITestFiles/ASCIITooMuchData.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Data (ASCIITestFiles/ASCIITooMuchData.pgm)";
then
    echo 'pgma2b - Correct Error Bad Data (Too Much) - PASSED' >> tests.out
else
    echo 'pgma2b - Correct Error Bad Data (Too Much) - FAILED' >> tests.out
fi

if ./pgma2b BinaryTestFiles/Binary.pgm bin/ASCIIToBinary.pgm | grep -q " (BinaryTestFiles/Binary.pgm)";
then
    echo 'pgma2b - Correct Error Bad Data (Too Much) - PASSED' >> tests.out
else
    echo 'pgma2b - Correct Error Bad Data (Too Much) - FAILED' >> tests.out
fi


echo >> out
echo Test Set 5: pgmb2a Errors
if ./pgmb2a Binary.pgm | grep -q "ERROR: Bad Argument Count";
then
    echo 'pgmb2a - Correct Bad Argument Count - PASSED' >> tests.out
else
    echo 'pgmb2a - Correct Bad Argument Count - FAILED' >> tests.out
fi

if ./pgmb2a Binaryd.pgm BinaryEchoed.pgm | grep -q "ERROR: Bad File Name (Binaryd.pgm)";
then
    echo 'pgmb2a - Correct Error Bad File Name - PASSED' >> tests.out
else
    echo 'pgmb2a - Correct Error Bad File Name - FAILED' >> tests.out
fi

if ./pgmb2a BinaryTestFiles/BinaryBadComment.pgm bin/Binary.pgm | grep -q "ERROR: Bad Comment Line (BinaryTestFiles/BinaryBadComment.pgm)";
then
    echo 'pgmb2a - Correct Error Bad Comment Line - PASSED' >> tests.out
else
    echo 'pgmb2a - Correct Error Bad Comment Line - FAILED' >> tests.out
fi

if ./pgmb2a BinaryTestFiles/BinaryBadComment.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Dimensions (BinaryTestFiles/BinaryBadComment.pgm)";
then
    echo 'pgmb2a - Correct Error Bad Dimensions - PASSED' >> tests.out
else
    echo 'pgmb2a - Correct Error Bad Dimensions - FAILED' >> tests.out
fi

if ./pgmb2a BinaryTestFiles/BinaryBadComment.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Magic Number (BinaryTestFiles/BinaryBadComment.pgm)";
then
    echo 'pgmb2a - Correct Error Bad Magic Number - PASSED' >> tests.out
else
    echo 'pgmb2a - Correct Error Bad Magic Number - FAILED' >> tests.out
fi

if ./pgmb2a BinaryTestFiles/BinaryBadComment.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Data (BinaryTestFiles/BinaryBadComment.pgm)";
then
    echo 'pgmb2a - Correct Error Bad Data (Too Little) - PASSED' >> tests.out
else
    echo 'pgmb2a - Correct Error Bad Data (Too Little) - FAILED' >> tests.out
fi

if ./pgmb2a BinaryTestFiles/BinaryBadComment.pgm bin/ASCIIEchoed.pgm | grep -q "ERROR: Bad Data (BinaryTestFiles/BinaryBadComment.pgm)";
then
    echo 'pgmb2a - Correct Error Bad Data (Too Much) - PASSED' >> tests.out
else
    echo 'pgmb2a - Correct Error Bad Data (Too Much) - FAILED' >> tests.out
fi

sleep 3