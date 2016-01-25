#もっと細かい説明がほしいのであればここにhttp://urin.github.io/posts/2013/simple-makefile-for-clang/

#コンパイラの指定 空欄でcc
CC      = gcc
#コンパイラオプション指定
CFLAGS  =
#リンクオプション指定
LDFLAGS =
#ライブラリの指定
LIBS    =
#インクルード系の指定 ここではローカルパスとwindowsようにncursesのパスを別に指定
INCLUDE = -I./include -I/usr/include/ncurses
#ソースコードフォルダの指定
SRC_DIR = ./source
#オブジェクトフォルダの指定 .oファイルをここに置く
OBJ_DIR = ./build
#ソースファイルの指定 lsコマンドを使用して.cファイル全てを指定
SOURCES = $(shell ls $(SRC_DIR)/*.c)
#オブジェクトの指定 SOURCESをそのまま.oにする
OBJS    = $(subst $(SRC_DIR),$(OBJ_DIR), $(SOURCES:.c=.o))
#ターゲット名の指定
TARGET  = Africa
#依存関係ファイル指定
DEPENDS = $(OBJS:.o=.d)
#オプション指定 ここではncursesコマンドを入力
OPTION = -lncurses


all: $(TARGET)

#オブジェクトファイルを結合
$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $(OBJS) $(OPTION) $(LDFLAGS)

#オブジェクトファイルを結合
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#buildフォルダがなかったら自動生成
	@if [ ! -d $(OBJ_DIR) ]; \
		then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
		fi
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

#削除時の指定コマンド オブジェクトファイル系を全て削除
clean:
	$(RM) $(OBJS) $(TARGET) $(DEPENDS)

-include $(DEPENDS)

.PHONY: all clean
