def conv(img, conv_filter):
   
    if len(img.shape)!=3 or len(conv_filter.shape)!=4:
        print("卷积运算所输入的维度不符合要求")
        sys.exit()
        
    if img.shape[-1] != conv_filter.shape[-1]:
        print("卷积输入图片与卷积核的通道数不一致")
        sys.exit()
        
    img_h, img_w, img_ch = img.shape
    filter_num, filter_h, filter_w, img_ch = conv_filter.shape
    feature_h = img_h - filter_h + 1
    feature_w = img_w - filter_w + 1

    # 初始化输出的特征图片，由于没有使用零填充，图片尺寸会减小
    img_out = np.zeros((feature_h, feature_w, filter_num))
    img_matrix = np.zeros((feature_h*feature_w, filter_h*filter_w*img_ch))
    filter_matrix = np.zeros((filter_h*filter_w*img_ch, filter_num))
    
    # 将输入图片张量转换成矩阵形式
    for i in range(feature_h*feature_w):
        for j in range(img_ch):
            img_matrix[i, j*filter_h*filter_w:(j+1)*filter_h*filter_w] = \
            img[np.uint16(i/feature_w):np.uint16(i/feature_w+filter_h),np.uint16(i%feature_w):np.uint16(i%feature_w+filter_w),j].reshape(filter_h*filter_w)
    
    # 将卷积核张量转换成矩阵形式
    for i in range(filter_num):
        filter_matrix[:,i] = conv_filter[i,:].reshape(filter_w*filter_h*img_ch)
    
    feature_matrix = np.dot(img_matrix, filter_matrix)
    
    for i in range(filter_num):
        img_out[:,:,i] = feature_matrix[:,i].reshape(feature_h, feature_w)
    
    return img_out