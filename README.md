# AviUtl プラグイン - UniteWindow

* 3.0.0 by 蛇色 - 2022/05/08 子ウィンドウにフォーカスが当たっていない問題を修正
* 2.0.0 by 蛇色 - 2022/05/08 各ウィンドウを子ウィンドウに変更
* 1.1.6 by 蛇色 - 2022/05/07 ボーダーに基点を追加
* 1.1.5 by 蛇色 - 2022/05/06 シングルウィンドウのクラス名を "AviUtl" に変更
* 1.1.4 by 蛇色 - 2022/05/06 ボーダーのスナップ機能を追加
* 1.1.3 by 蛇色 - 2022/05/06 スポイトが動作しない問題を修正
* 1.1.2 by 蛇色 - 2022/05/06 各ウィンドウが操作不能になる問題を修正
* 1.1.1 by 蛇色 - 2022/05/05 ウィンドウをクリックしても最前面にならなかった問題を修正
* 1.1.0 by 蛇色 - 2022/05/05 Shift キードラッグでボーダーを十字にできるように修正
* 1.0.7 by 蛇色 - 2022/05/04 パフォーマンスの低下を改善
* 1.0.6 by 蛇色 - 2022/05/04 「拡張編集RAMプレビュー」が動作しない問題に対応
* 1.0.5 by 蛇色 - 2022/05/04 「イージング設定時短プラグイン」が動作しない問題に対応
* 1.0.4 by 蛇色 - 2022/05/04 スピンボタンで数値を変更できないバグを修正
* 1.0.3 by 蛇色 - 2022/05/04 「PSDToolKit」の「送る」に対応
* 1.0.2 by 蛇色 - 2022/05/04 マウスホイールでスクロールに対応
* 1.0.1 by 蛇色 - 2022/05/04 「テキスト編集補助プラグイン」が動作しない問題に対応
* 1.0.0 by 蛇色 - 2022/05/03 初版

AviUtl のウィンドウを結合してシングルウィンドウにまとめます。

![UniteWindow 1 0 0](https://user-images.githubusercontent.com/96464759/166472528-057c3fff-f724-40d2-9692-8a647e966f80.jpg)

## 導入方法

1. 以下のファイルを AviUtl の Plugins フォルダに配置します。
	* UniteWindow.aul
	* UniteWindow.xml
	* UniteWindow (フォルダ)

## 使用方法

ボーダーをドラッグしてペインのサイズを調整します。Shift キーを押したままドラッグするとボーダーが十字になるように調整されます。

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
		* エディットボックスの下にあるコンボボックスで基点を指定します。例えばボーダーを右端で固定したい場合は基点を「右下」に設定します。

### 設定ファイル

UniteWindow.xml をテキストエディタで開いて編集します。

* ```<config>```
	* ```borderWidth``` ボーダーの幅を指定します。
	* ```captionHeight``` キャプションの高さを指定します。
	* ```borderSnapRange``` ボーダーのスナップ範囲を指定します。
	* ```fillColor``` 背景の塗りつぶし色を指定します。
	* ```borderColor``` ボーダーの色を指定します。
	* ```hotBorderColor``` ホット状態のボーダーの色を指定します。
	* ```activeCaptionColor``` アクティブなキャプションの色を指定します。
	* ```activeCaptionTextColor``` アクティブなキャプションのテキストの色を指定します。
	* ```inactiveCaptionColor``` 非アクティブなキャプションの色を指定します。
	* ```inactiveCaptionTextColor``` 非アクティブなキャプションのテキストの色を指定します。
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
			* ```centerOrigin``` 中央にある垂直ボーダーの基点を指定します。
			* ```leftOrigin``` 左側にある水平ボーダーの基点を指定します。
			* ```rightOrigin``` 右側にある水平ボーダーの基点を指定します。
		* ```<horzSplit>``` ```layoutMode``` が ```horzSplit``` のときのボーダーの位置を指定します。
			* ```center``` 中央にある水平ボーダーの Y 座標を指定します。
			* ```top``` 上側にある垂直ボーダーの X 座標を指定します。
			* ```bottom``` 下側にある垂直ボーダーの X 座標を指定します。
			* ```centerOrigin``` 中央にある水平ボーダーの基点を指定します。
			* ```topOrigin``` 上側にある垂直ボーダーの基点を指定します。
			* ```bottomOrigin``` 下側にある垂直ボーダーの基点を指定します。

## 動作確認

* (必須) AviUtl 1.10 & 拡張編集 0.92 http://spring-fragrance.mints.ne.jp/aviutl/
* (共存確認) patch.aul r21 https://scrapbox.io/ePi5131/patch.aul

## クレジット

* Microsoft Research Detours Package https://github.com/microsoft/Detours
* aviutl_exedit_sdk https://github.com/ePi5131/aviutl_exedit_sdk
* Common Library https://github.com/hebiiro/Common-Library
