aux_source_directory(. LIB_DIR_SRCS) # 将./下的所有文件名付给 ${DIR_SRCS}

add_library(hi ${LIB_DIR_SRCS}) # 添加要生成的库文件

install(TARGETS hi DESTINATION lib EXPORT hiTargets) # export should be used with top level cmake install EXPORT
install(FILES hi.h DESTINATION include)