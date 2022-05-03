# AviUtl プラグイン - UniteWindow

* 1.0.0 by 蛇色 - 2022/05/03 初版

AviUtl のウィンドウを結合してシングルウィンドウにまとめます。

![UniteWindow 1 0 0](https://user-images.githubusercontent.com/96464759/166472528-057c3fff-f724-40d2-9692-8a647e966f80.jpg)

## 導入方法

1. 以下のファイルを AviUtl の Plugins フォルダに配置します。
	* UniteWindow.aul
	* UniteWindow.xml
	* UniteWindow (フォルダ)

## 設定方法

タイトルバーを右クリックしてシステムメニューを表示します。

### レイアウトのインポート

レイアウトファイルを選択してインポートします。

### レイアウトのエクスポート

レイアウトファイルを選択してエクスポートします。

### UniteWindowの設定

UniteWindowの設定ダイアログを開きます。

* ```レイアウトモード```
	* ```垂直分割``` 最初に垂直ボーダーで分割するモードです。水平ボーダーは個別に位置調整ができます。
	* ```水平分割``` 最初に水平ボーダーで分割するモードです。垂直ボーダーは個別に位置調整ができます。

* ```ウィンドウの配置```
	* ```左上```
	* ```右上```
	* ```左下```
	* ```右下```
		* それぞれに ```AviUtlウィンドウ```、```拡張編集ウィンドウ```、```設定ダイアログ```、```ウィンドウなし``` を指定できます。同じウィンドウを重複して指定することはできません。

* ```ボーダー位置 (垂直分割)``` 垂直分割モードのボーダーの位置を指定します。
	* ```中央``` 中央にある垂直ボーダーの X 座標を指定します。
	* ```左``` 左側にある水平ボーダーの Y 座標を指定します。
	* ```右``` 右側にある水平ボーダーの Y 座標を指定します。

* ```ボーダー位置 (水平分割)``` 水平分割モードのボーダーの位置を指定します。
	* ```中央``` 中央にある水平ボーダーの Y 座標を指定します。
	* ```上``` 上側にある垂直ボーダーの X 座標を指定します。
	* ```下``` 下側にある垂直ボーダーの X 座標を指定します。

### 設定ファイル

UniteWindow.xml をテキストエディタで開いて編集します。

* ```<config>```
	* ```borderWidth``` ボーダーの幅を指定します。
	* ```captionHeight``` キャプションの高さを指定します。
	* ```fillColor``` 背景の塗りつぶし色を指定します。
	* ```borderColor``` 現在使用されていません。
	* ```hotBorderColor``` ホット状態のボーダーの色を指定します。
	* ```<singleWindow>``` シングルウィンドウの位置を指定します。ウィンドウ位置がおかしくなった場合はこのタグを削除してください。
	* ```<layout>``` レイアウトを指定します。レイアウトがおかしくなった場合はこのタグを削除してください。
		* ```layoutMode``` ```vertSplit```、```horzSplit``` のいずれかを指定します。
		* ```<window>```
			* ```pos``` ```topLeft```、```topRight```、```bottomLeft```、```bottomRight``` のいずれかを指定します。
			* ```id``` ```aviutlWindow```、```exeditWindow```、```settingDialog```、空文字のいずれかを指定します。
		* ```<vertSplit>``` ```layoutMode``` が ```vertSplit``` のときのボーダーの位置を指定します。
			* ```center``` 中央にある垂直ボーダーの X 座標を指定します。
			* ```left``` 左側にある水平ボーダーの Y 座標を指定します。
			* ```right``` 右側にある水平ボーダーの Y 座標を指定します。
		* ```<horzSplit>``` ```layoutMode``` が ```horzSplit``` のときのボーダーの位置を指定します。
			* ```center``` 中央にある水平ボーダーの Y 座標を指定します。
			* ```top``` 上側にある垂直ボーダーの X 座標を指定します。
			* ```bottom``` 下側にある垂直ボーダーの X 座標を指定します。

## 動作確認

* (必須) AviUtl 1.10 & 拡張編集 0.92 http://spring-fragrance.mints.ne.jp/aviutl/
* (共存確認) patch.aul r21 https://scrapbox.io/ePi5131/patch.aul

## クレジット

* Microsoft Research Detours Package https://github.com/microsoft/Detours
* aviutl_exedit_sdk https://github.com/ePi5131/aviutl_exedit_sdk
* Common Library https://github.com/hebiiro/Common-Library
