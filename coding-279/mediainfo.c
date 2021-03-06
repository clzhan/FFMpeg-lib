#include <libavformat/avformat.h>

int main(int argc, char *argv[])
{
    int err_code;
    char errors[1024];

    AVFormatContext *fmt_ctx = NULL;

    if(argc < 2){
        fprintf(stderr, "[Usage]you should input media file!\n");
        return -1;
    }

    char *src_filename = argv[1];

    //av_register_all();

    /* open input file, and allocate format context */
    if ((err_code=avformat_open_input(&fmt_ctx, src_filename, NULL, NULL)) < 0) {
        av_strerror(err_code, errors, 1024);
        fprintf(stderr, "Could not open source file %s, %d(%s)\n", src_filename, err_code, errors);
        exit(1);
    }

    /* retreive stream information */
    if((err_code = avformat_find_stream_info(fmt_ctx, NULL)) < 0) {
        av_strerror(err_code, errors, 1024);
        fprintf(stderr, "Could not open source file %s, %d(%s)\n", src_filename, err_code, errors);
        exit(1);
    }

    /* dump input information to stderr */
    av_dump_format(fmt_ctx, 0, src_filename, 0);

    /* close input file */
    avformat_close_input(&fmt_ctx);

    return 0;
}
