BUILD_DIR=build
if [ -d $BUILD_DIR ]; then
  $BUILD_DIR/Compiler $1
else
  echo "Directory build doesn't exists."
fi